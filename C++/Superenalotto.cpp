#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> s;
    int n, cont = 0;
    
    
    while (true) {
        cin >> n;
        if (n == 0) {
            cont++;
            if (cont > 1) {
                break;  
            }
        } else {
            cont = 0;
        }
        s.push_back(n);
    }
    
   
    srand(time(0));
    unordered_set<int> v;  
    while (v.size() < 6) {
        v.insert(1 + rand() % 90);  
    }
    

    cout << "Numeri estratti: ";
    for (auto num : v) {
        cout << num << " ";
    }
    cout << endl;

    unordered_set<int> azzeccatiGlobali;  
    vector<int> temp;  
    int totaleAzzeccati = 0;  

  
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 0) {
            temp.push_back(s[i]);  
        } else if (!temp.empty()) {  
            int matched = 0;  
            for (int n = 0; n < temp.size(); n++) {
                cout << temp[n] << " "; 
                if (v.find(temp[n]) != v.end() && azzeccatiGlobali.find(temp[n]) == azzeccatiGlobali.end()) {
                    matched++;  
                    azzeccatiGlobali.insert(temp[n]);  
                }
            }
            cout << "- numeri azzeccati " << matched << endl;
            totaleAzzeccati += matched;  
            temp.clear();  
        }
    }

   
    cout << "Totale numeri azzeccati: " << totaleAzzeccati << endl;

    return 0;
}
