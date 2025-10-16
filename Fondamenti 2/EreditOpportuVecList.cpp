#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// Esercizio 1: FakeList

class FakeList : protected list<int> {
public:
    int getFakeSize() const {
        return this->size() * 2;
    }

    void insert(int el) {
        bool found = (find(this->begin(), this->end(), el) != this->end());
        if (found) {
            this->push_back(el);
        } else {
            this->push_front(el);
        }
    }

    void fakeSort(bool ascending) {
        if (ascending) {
            this->sort();
        } else {
            this->sort(greater<int>());
        }
    }

    void fakeClear(bool c) {
        if (c) {
            this->clear();
        }
    }
};


// Esercizio 2: VettorePazzo

class VettorePazzo : protected vector<int> {
    private:
        int numeroPazzo;

    public:
        VettorePazzo(int pazzo) : numeroPazzo(pazzo) {}

        void aggiunta(int val) {
            if (val != numeroPazzo && val % numeroPazzo != 0) {
                this->push_back(val);
            }
        }

        int& operator[](size_t index) {
            return this->at(index);
        }

        const int& operator[](size_t index) const {
            return this->at(index);
        }

        bool operator<(const VettorePazzo& other) const {
            return this->numeroPazzo < other.numeroPazzo;
        }

        bool operator==(const VettorePazzo& other) const {
            return true;
        }
};

