#include <iostream>
using namespace std;

void molt(int* a) {
    *a *= 2; 
}
//BOXER TVB BY ROSX IHIHIHIH
int main() {
    int c;
    cin >> c;  

    molt(&c);  
    cout << c;

    return 0;
}  
