#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int m[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int maxDim = 1; 
    int startX = 0, startY = 0; 
    int numero = m[0][0]; 

    
    int dp[n][n];

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 1;
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 2; j >= 0; j--) {
           
            if (m[i][j] == m[i + 1][j] && m[i][j] == m[i][j + 1] && m[i][j] == m[i + 1][j + 1]) {
                dp[i][j] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]) + 1;
            }

            
            if (dp[i][j] > maxDim) {
                maxDim = dp[i][j];
                startX = i;
                startY = j;
                numero = m[i][j];
            }
        }
    }

    cout << maxDim << " " << startX << " " << startY << " " << numero << endl;

    return 0;
}
