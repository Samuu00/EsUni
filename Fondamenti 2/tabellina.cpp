#include <iostream>
using namespace std;

int main() {
    int m, n;

    cin >> m;
    cin >> n;

    if (m >= 1 && n >= 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << j << "x" << i << "=" << (j * i);
                if (j < m) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Entrambi i valori devono essere maggiori o uguali a 1." << endl;
    }

    return 0;
}
