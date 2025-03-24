#include <iostream>
using namespace std;

class StackInteressi {
    private:
        double tassoInteressi;
        int size;
        double* array;
    public:
        StackInteressi() {
            tassoInteressi = 0.0;
            size = 0;
            array = nullptr;
        }
        StackInteressi(const StackInteressi& s) {
            tassoInteressi = s.tassoInteressi;
            size = s.size;
            array = new double[size];
            for(int i = 0; i < size; i++) {
                array[i] = s.array[i];
            }
        }
        StackInteressi& operator=(const StackInteressi& s) {
            tassoInteressi = s.tassoInteressi;
            size = s.size;
            array = new double[size];
            for(int i = 0; i < size; i++) {
                array[i] = s.array[i];
            }
            return *this;
        }
        void setTassoInteressi(double tasso) {
            tassoInteressi = tasso;
        }
        double getTassoInteressi() {
            return tassoInteressi;
        }

         void push(double nElemento) {
            double* newArray = new double[size + 1];
            newArray[0] = nElemento;  
            for (int i = 0; i < size; i++) {
                newArray[i + 1] = array[i];  
            }
            delete[] array;
            array = newArray;
            size++;
        }
        double pop() {
            double tasso = 0;
            for(int i = 0; i < size; i++) {
                if(i == 0) {
                    tasso = array[i]*tassoInteressi;
                    double* newArray = new double[size - 1];
                    for(int j = 1; j < size; j++) {
                        newArray[j-1] = array[j];
                    }
                    delete[] array;
                    array = newArray;
                    size--;
                }
            }
            return tasso;
        }
        ~StackInteressi() {
            delete[] array;
        }

};
int main(){
    StackInteressi s;
    s.setTassoInteressi(1.75);
    double* array = new double[2];
    s.push(8.0);
    s.push(4.0);
    cout << s.pop() << endl;
    return 0;
}
