#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[n][n]; 

    int somma = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    
    for (int i = 0; i < n; i++){
		for (int j = 0; j < n ; j++){
			
			if (i+j == n-1){
				somma += mat[i][j];
				
				}
			
			}
		
		
		}
		
	cout << "Somma diagonale inversa: " << somma << endl;
	
}
