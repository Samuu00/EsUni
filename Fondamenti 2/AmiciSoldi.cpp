#include <iostream>
#include <vector>
#include <map>
using namespace std;

class GestioneDebiti{
    private:
        map<string, int> amici;
        vector<vector<float>> prestiti;

    public:
        GestioneDebiti(vector<string> a) : prestiti(amici.size(), vector<float>(amici.size(), 0)) {
            for(int i = 0; i < a.size(); i++){
                amici[a[i]] = i;
            }
        }
        
        void anticipa(string x, string y, float k){
            int ix = amici.at(x);
             if(y == "*"){
                int div = k / prestiti.size();
                for(int i = 0; i < prestiti.size(); i++){
                        if(i == ix) continue;
                        prestiti[i][ix] += div;
                    }
                }
                else{

                    int iy = amici.at(y);
                    prestiti[iy][ix] += k;
                }
            }
        
        float saldo(string x, string y){
            int ix = amici.at(x);
            int iy = amici.at(y);

            float xy = prestiti[ix][iy];
            float yx = prestiti[iy][ix];

            return (xy - yx > 0) ? xy - yx : 0;
        }

        void paga(string x, string y, float k){
            int ix = amici.at(x);
            int iy = amici.at(y);

            if(saldo(x, y) >= 0 && k <= saldo(x, y)){
                prestiti[ix][iy] -= k;
                prestiti[iy][ix] = 0;
            }
        }
};
