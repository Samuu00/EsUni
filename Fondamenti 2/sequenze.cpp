#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> s1;
    int num;

    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        s1.push_back(num);
    }

    vector<int> s2;
    int n;
    
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        s2.push_back(n);
    }

    
    int cont = 0;
    int pos = -1;

    for (int i = 0; i <= s1.size() - s2.size(); i++) {
        cont = 0;
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i + j] == s2[j]) {
                cont++;
            } else {
                break;
            }
        }
        if (cont == s2.size()) {
            pos = i;
            break;
        }
    }

    
    if (pos != -1) {
        cout << pos <<endl;
    } else {
        cout << "Sottosequenza non trovata" <<endl;
    }
}
