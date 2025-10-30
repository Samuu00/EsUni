#include <iostream>
#include <list>
#include <string> 
using namespace std;

template <typename t>
class HashTable{
    private:
        static const int hashGroup = 10;
        list<pair<int, t>> table[hashGroup];
        
    public:
        int hashFunc(int key){
            return key % hashGroup;
        }

        bool isEmpty(){
            int sum = 0;
            for(int i = 0; i < hashGroup; i++){
                sum += table[i].size();
            }

            if(sum > 0) return false;

            return true;
        }

        void insert(int key, t value){
            int hashKey = hashFunc(key);
            auto& cell = table[hashKey]; 
            auto itr = begin(cell);
            bool exists = false;

            for(; itr != cell.end(); itr++){ 
                if(itr->first == key){
                    itr->second = value;
                    exists = true;
                    break;
                }
            }

            if(!exists) cell.emplace_back(key, value);
        }

        auto find(int key){
            int hashKey = hashFunc(key);
            auto& cell = table[hashKey]; 
            auto itr = begin(cell);

            for(; itr != cell.end(); itr++){ 
                if(itr->first == key) return itr;
            }

            return cell.end(); 
        }

        void erase(int key){
            int hashKey = hashFunc(key);
            auto& cell = table[hashKey]; 
            auto itr = begin(cell);

            for(; itr != cell.end(); itr++){ 
                if(itr->first == key){
                    cell.erase(itr);
                    break;
                }
            }
        }

        void printTable(){
            for(int i = 0; i < hashGroup; i++){
                if(table[i].size() == 0) continue;

                cout<< i << ": ";
                for(auto itr = table[i].begin(); itr != table[i].end(); itr++){
                    cout << "{" << itr->first << ", " << itr->second << "} -> ";
                }
                cout<< "NULL" <<endl; 
            }
        }
};

int main(){
    HashTable<string> ht;

    if(ht.isEmpty()){
        cout<< "vuota" <<endl;
    }else{
        cout<< "qualcosa c'è" <<endl;
    }

    ht.insert(45, "ciao");
    ht.insert(906, "ciaao");
    ht.insert(150, "no");
    ht.insert(500, "si");
    ht.insert(12000, "pisello");
    ht.insert(2450, "si");
    ht.insert(50, "ok"); 

    ht.printTable();

    cout << "\nDopo erase(45):\n";
    ht.erase(45);

    ht.printTable(); 

    if(ht.isEmpty()){
        cout<< "vuota" <<endl;
    }else{
        cout<< "qualcosa c'è" <<endl;
    }

    return 0;
}