#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Inserire la dimensione della matrice quadrata: ";  
    cin >> n;
    int mat[n][n], l[n]; 

    int somma = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

   
    for (int j = 0; j < n; j++) {
		somma = 0;
        for (int i = 0; i < n; i++) {
			somma += mat[i][j];
		}
		l[j] = somma;
    }
    
    cout << "matrice:"<<endl;
    for (int i = 0; i < n; i++) {
        cout <<endl;
        for (int j = 0; j < n; j++) {

            cout << mat[i][j];
        }
    }
    
    cout << endl;

    cout << "Somma colonne: ";
    for (int j = 0; j < n; j++) {
        cout << l[j] << " ";
    }
    
    cout << endl;

    return 0;
}

