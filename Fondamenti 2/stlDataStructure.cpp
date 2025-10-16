#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>
#include <list>
#include <functional>
using namespace std;

template <typename T>
class Vector {
    private:
        T* data_;
        size_t size_;
        size_t capacity_;

    public:
        using iterator = T*;

        Vector() : data_(nullptr), size_(0), capacity_(0) {}
        ~Vector() { delete[] data_; }

        void push_back(const T& value) {
            if (size_ >= capacity_) {
                reserve(capacity_ == 0 ? 1 : capacity_ * 2);
            }
            data_[size_++] = value;
        }
        
        void pop_back() {
            if (size_ > 0) {
                --size_;
            }
        }

        iterator erase(iterator pos) {
            if (pos < begin() || pos >= end()) {
                throw out_of_range("Iterator out of range");
            }
            move(pos + 1, end(), pos);
            --size_;
            return pos;
        }

        void reserve(size_t new_capacity) {
            if (new_capacity <= capacity_) return;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = move(data_[i]);
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        
        T& operator[](size_t index) { return data_[index]; }
        size_t size() const { return size_; }

        iterator begin() { return data_; }
        iterator end() { return data_ + size_; }
};

template <typename T>
class List {
    private:
        struct Node {
            T data;
            Node* prev;
            Node* next;
            Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
        };

        Node* head;
        Node* tail;

    public:
        class iterator {
        public:
            Node* current_node;
            iterator(Node* node) : current_node(node) {}
            T& operator*() { return current_node->data; }
            iterator& operator++() { current_node = current_node->next; return *this; }
            bool operator!=(const iterator& other) const { return this->current_node != other.current_node; }
        };

        List() : head(nullptr), tail(nullptr) {}
        ~List() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void push_back(const T& value) {
            Node* newNode = new Node(value);
            if (!tail) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void pop_back() {
            if (!tail) return;
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }

        iterator erase(iterator pos) {
            Node* to_delete = pos.current_node;
            Node* next_node = to_delete->next;
            
            if (to_delete->prev) {
                to_delete->prev->next = to_delete->next;
            } else {
                head = to_delete->next;
            }

            if (to_delete->next) {
                to_delete->next->prev = to_delete->prev;
            } else {
                tail = to_delete->prev;
            }

            delete to_delete;
            return iterator(next_node);
        }

        iterator begin() { return iterator(head); }
        iterator end() { return iterator(nullptr); }
};

template <typename Key, typename Value>
class Map {
    private:
        struct Node {
            pair<const Key, Value> data;
            Node *left, *right, *parent;
            Node(const pair<const Key, Value>& p) : data(p), left(nullptr), right(nullptr), parent(nullptr) {}
        };
        Node* root;

        Node* find_node(const Key& key) {
            Node* current = root;
            while(current) {
                if (key < current->data.first) current = current->left;
                else if (key > current->data.first) current = current->right;
                else return current;
            }
            return nullptr;
        }

        Node* get_minimum(Node* n) {
            while (n && n->left) n = n->left;
            return n;
        }

        void transplant(Node* u, Node* v) {
            if (!u->parent) root = v;
            else if (u == u->parent->left) u->parent->left = v;
            else u->parent->right = v;
            if (v) v->parent = u->parent;
        }

    public:
        class iterator {
        public:
            Node* current_node;
            iterator(Node* n) : current_node(n) {}
            pair<const Key, Value>& operator*() { return current_node->data; }
            iterator& operator++() {
                if (current_node->right) {
                    current_node = get_minimum(current_node->right);
                } else {
                    Node* p = current_node->parent;
                    while (p && current_node == p->right) { current_node = p; p = p->parent; }
                    current_node = p;
                }
                return *this;
            }
            bool operator!=(const iterator& other) const { return current_node != other.current_node; }
        };
        
        Map() : root(nullptr) {}
        
        Value& operator[](const Key& key) {
            Node* found = find_node(key);
            if (found) return found->data.second;
            
            Node* current = root;
            Node* parent = nullptr;
            while(current) {
                parent = current;
                if (key < current->data.first) current = current->left;
                else current = current->right;
            }
            
            Node* newNode = new Node({key, Value()});
            newNode->parent = parent;
            if (!parent) root = newNode;
            else if (key < parent->data.first) parent->left = newNode;
            else parent->right = newNode;
            
            return newNode->data.second;
        }
        
        void erase(const Key& key) {
            Node* z = find_node(key);
            if (!z) return;

            if (!z->left) {
                transplant(z, z->right);
            } else if (!z->right) {
                transplant(z, z->left);
            } else {
                Node* y = get_minimum(z->right);
                if (y->parent != z) {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
            }
            delete z;
        }

        iterator begin() { return iterator(get_minimum(root)); }
        iterator end() { return iterator(nullptr); }
};

template <typename Key, typename Value, typename Hasher = hash<Key>>
class Unordered_Map {
    private:
        using Bucket = list<pair<const Key, Value>>;
        vector<Bucket> table;
        size_t num_elements;
        Hasher hasher;

    public:
        class iterator {
        public:
            Unordered_Map* map_ptr;
            size_t bucket_index;
            typename Bucket::iterator list_it;
            iterator(Unordered_Map* map, size_t b_idx, typename Bucket::iterator l_it) 
                : map_ptr(map), bucket_index(b_idx), list_it(l_it) {}

            pair<const Key, Value>& operator*() { return *list_it; }
            iterator& operator++() {
                ++list_it;
                if (list_it == map_ptr->table[bucket_index].end()) {
                    bucket_index++;
                    while (bucket_index < map_ptr->table.size() && map_ptr->table[bucket_index].empty()) {
                        bucket_index++;
                    }
                    if (bucket_index < map_ptr->table.size()) {
                        list_it = map_ptr->table[bucket_index].begin();
                    } else {
                        list_it = typename Bucket::iterator();
                    }
                }
                return *this;
            }
            bool operator!=(const iterator& other) const {
                return bucket_index != other.bucket_index || list_it != other.list_it;
            }
        };
        
        Unordered_Map(size_t bucket_count = 101) : table(bucket_count), num_elements(0) {}

        Value& operator[](const Key& key) {
            size_t index = hasher(key) % table.size();
            for (auto& pair : table[index]) {
                if (pair.first == key) return pair.second;
            }
            table[index].emplace_front(key, Value());
            num_elements++;
            return table[index].front().second;
        }

        size_t erase(const Key& key) {
            size_t index = hasher(key) % table.size();
            auto& bucket = table[index];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (it->first == key) {
                    bucket.erase(it);
                    num_elements--;
                    return 1;
                }
            }
            return 0;
        }

        iterator begin() {
            size_t first_bucket = 0;
            while (first_bucket < table.size() && table[first_bucket].empty()) {
                first_bucket++;
            }
            if (first_bucket == table.size()) return end();
            return iterator(this, first_bucket, table[first_bucket].begin());
        }
        
        iterator end() {
            return iterator(this, table.size(), typename Bucket::iterator());
        }
};

template <typename Key>
class Set {
    private:
        struct Node {
            Key key;
            Node *left, *right, *parent;
            Node(const Key& k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
        };
        Node* root;

        Node* find_node(const Key& key) {
            Node* current = root;
            while(current) {
                if (key < current->key) current = current->left;
                else if (key > current->key) current = current->right;
                else return current;
            }
            return nullptr;
        }

        Node* get_minimum(Node* n) {
            while (n && n->left) n = n->left;
            return n;
        }
        
        void transplant(Node* u, Node* v) {
            if (!u->parent) root = v;
            else if (u == u->parent->left) u->parent->left = v;
            else u->parent->right = v;
            if (v) v->parent = u->parent;
        }

    public:
        class iterator {
        private:
            Node* current_node;
        public:
            iterator(Node* n) : current_node(n) {}
            const Key& operator*() { return current_node->key; }
            iterator& operator++() {
                if (current_node->right) {
                    current_node = get_minimum(current_node->right);
                } else {
                    Node* p = current_node->parent;
                    while (p && current_node == p->right) { current_node = p; p = p->parent; }
                    current_node = p;
                }
                return *this;
            }
            bool operator!=(const iterator& other) const { return current_node != other.current_node; }
        };
        
        Set() : root(nullptr) {}
        
        void insert(const Key& key) {
            Node* found = find_node(key);
            if (found) return;

            Node* current = root;
            Node* parent = nullptr;
            while(current) {
                parent = current;
                if (key < current->key) current = current->left;
                else current = current->right;
            }
            Node* newNode = new Node(key);
            newNode->parent = parent;
            if (!parent) root = newNode;
            else if (key < parent->key) parent->left = newNode;
            else parent->right = newNode;
        }

        size_t erase(const Key& key) {
            Node* z = find_node(key);
            if (!z) return 0;

            if (!z->left) {
                transplant(z, z->right);
            } else if (!z->right) {
                transplant(z, z->left);
            } else {
                Node* y = get_minimum(z->right);
                if (y->parent != z) {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
            }
            delete z;
            return 1;
        }

        iterator begin() { return iterator(get_minimum(root)); }
        iterator end() { return iterator(nullptr); }
};

template <typename Key, typename Hasher = hash<Key>>
class Unordered_Set {
    private:
        using Bucket = list<Key>;
        vector<Bucket> table;
        size_t num_elements;
        Hasher hasher;

    public:
        class iterator {
        public:
            Unordered_Set* set_ptr;
            size_t bucket_index;
            typename Bucket::iterator list_it;
            iterator(Unordered_Set* set, size_t b_idx, typename Bucket::iterator l_it)
                : set_ptr(set), bucket_index(b_idx), list_it(l_it) {}
            
            const Key& operator*() { return *list_it; }
            iterator& operator++() {
                ++list_it;
                if (list_it == set_ptr->table[bucket_index].end()) {
                    bucket_index++;
                    while (bucket_index < set_ptr->table.size() && set_ptr->table[bucket_index].empty()) {
                        bucket_index++;
                    }
                    if (bucket_index < set_ptr->table.size()) {
                        list_it = set_ptr->table[bucket_index].begin();
                    } else {
                        list_it = typename Bucket::iterator();
                    }
                }
                return *this;
            }
            bool operator!=(const iterator& other) const {
                return bucket_index != other.bucket_index || list_it != other.list_it;
            }
        };
        
        Unordered_Set(size_t bucket_count = 101) : table(bucket_count), num_elements(0) {}

        void insert(const Key& key) {
            size_t index = hasher(key) % table.size();
            for (const auto& elem : table[index]) {
                if (elem == key) return;
            }
            table[index].push_front(key);
            num_elements++;
        }

        size_t erase(const Key& key) {
            size_t index = hasher(key) % table.size();
            auto& bucket = table[index];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (*it == key) {
                    bucket.erase(it);
                    num_elements--;
                    return 1;
                }
            }
            return 0;
        }

        iterator begin() {
            size_t first_bucket = 0;
            while (first_bucket < table.size() && table[first_bucket].empty()) {
                first_bucket++;
            }
            if (first_bucket == table.size()) return end();
            return iterator(this, first_bucket, table[first_bucket].begin());
        }

        iterator end() {
            return iterator(this, table.size(), typename Bucket::iterator());
        }
};

template <typename T, typename Container = vector<T>>
class Stack {
    protected:
        Container c;

    public:
        Stack() = default;

        bool empty() const {
            return c.empty();
        }

        size_t size() const {
            return c.size();
        }

        T& top() {
            if (c.empty()) {
                throw out_of_range("Stack is empty");
            }
            return c.back();
        }

        const T& top() const {
            if (c.empty()) {
                throw out_of_range("Stack is empty");
            }
            return c.back();
        }

        void push(const T& value) {
            c.push_back(value);
        }

        void pop() {
            if (c.empty()) {
                throw out_of_range("Pop from empty stack");
            }
            c.pop_back();
        }
};

template <typename T, typename Container = deque<T>>
class Queue {
    protected:
        Container c;

    public:
        Queue() = default;

        bool empty() const {
            return c.empty();
        }

        size_t size() const {
            return c.size();
        }

        T& front() {
            if (c.empty()) {
                throw out_of_range("Queue is empty");
            }
            return c.front();
        }

        const T& front() const {
            if (c.empty()) {
                throw out_of_range("Queue is empty");
            }
            return c.front();
        }
        
        T& back() {
            if (c.empty()) {
                throw out_of_range("Queue is empty");
            }
            return c.back();
        }

        const T& back() const {
            if (c.empty()) {
                throw out_of_range("Queue is empty");
            }
            return c.back();
        }

        void push(const T& value) {
            c.push_back(value);
        }

        void pop() {
            if (c.empty()) {
                throw out_of_range("Pop from empty queue");
            }
            c.pop_front();
        }
};