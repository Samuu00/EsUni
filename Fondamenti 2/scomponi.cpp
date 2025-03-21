#include <iostream>
using namespace std;

void scomponi(int numero) {
    if (numero <= 0) {
        return;
    }
    if (numero == 1){
        cout << "1" << endl;
        return;
    }
    
    int fattore = 2; 
    while (numero > 1) {
        int count = 0; 
        
        
        while (numero % fattore == 0) {
            numero /= fattore; 
            count++; 
        }
        
      
        if (count > 0) {
            cout << fattore << "^" << count;
            
            if (numero > 1) {
                cout << " * ";
            }
        }
        fattore++; 
    }
    cout << endl; 
}

int main() {
    int numero;
    cin >> numero; 
    scomponi(numero); 
    return 0;
}
