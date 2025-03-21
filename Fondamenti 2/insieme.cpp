#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> l;
    int num;
    while (true) {
        cin >> num;
        if (num == -1){
            break;
        }
        l.push_back(num);
    }

    int len = l.size();
    int cont = 0;
    bool inSet = false; 

    if (l[0] == 0) {
        cont++; 
    }

    for (int i = 0; i < len; i++) {
        if (l[i] != 0) {
            if (!inSet) {
                cont++; 
                inSet = true;
            }
        } else {
            inSet = false; 
        }
    
    if (l[i] == 0 && l[i+1] == 0){
        if (l[len-1] == 0) {
            cont -= 1; 
    }
    cont++;
    }
    }

    cout << "Cardinalita: " << cont << endl;

    vector<int> c;
    int contt = 0;
    for (int i = 0; i < len; i++){
        if (l[i] == 0){
            if (contt > 0) {
                c.push_back(contt);
                contt = 0;
            } else {
                c.push_back(0); 
            }
        } else {
            contt++;
        }
    }
    if (contt > 0) {
        c.push_back(contt);
    }

    int lenght = c.size();
    int cmax = c[0];
    int cmin = c[0];
    for (int i = 0; i < lenght; i++) {
        if (c[i] > cmax) {
            cmax = c[i];
        }
    }
    cout<<"Cardinalita massima: "<< cmax<<endl;

    for (int i = 0; i < lenght; i++) {
        if (c[i] < cmin) {
            cmin = c[i];
        }
    }
    if (cmin == 0){
        string cminStr = "Vuoto";
        cout<<"Cardinalita minima: "<< cminStr <<endl;
    }
    else {
        cout<<"Cardinalita minima: "<< cmin <<endl;
    }

    return 0;
}