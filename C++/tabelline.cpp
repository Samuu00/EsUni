#include <iostream>
using namespace std;

int main() {
    
    cout << "\t";  
    for (int j = 1; j < 10; j++) {
        cout << j << "\t";  
    }
    cout << endl;

   
    for (int i = 1; i < 10; i++) {
        cout << i << "\t";  
        for (int j = 1; j < 10; j++) {
            cout << i * j << "\t";  
        }
        cout << endl;  
    }

    return 0;
}
