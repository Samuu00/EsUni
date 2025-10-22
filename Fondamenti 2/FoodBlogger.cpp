#include <iostream>
#include <vector>
#include <map>

class OrgRec{
    private:
        map<pair<string, string>, recensione> recensioni;
    
    public:
        void aggRec(ristorante& r, int vP, int vQ, int vL, int vO){
            recensioni[{r.nome, r.località}] = recensione(vP, vQ, vL, vO); 
        }

        int retValut(ristorante& r, string cat){
            auto it = recensioni.find({r.nome, r.località});

            if(it == recensioni.end()) return -1;

            if(cat == "P") return recensioni[{r.nome, r.località}].votoPrezz;
            if(cat == "Q") return recensioni[{r.nome, r.località}].votoQual;
            if(cat == "L") return recensioni[{r.nome, r.località}].votoLoc;
            if(cat == "O") return recensioni[{r.nome, r.località}].votoOrig;
        }

        vector<pair<string, string>> retRist(int x, string a){
            vector<pair<string, string>> risto;
            if(a == "P"){
                for(auto& it : recensioni){
                    if(it.second.votoPrezz > x) risto.push_back(it.first);
                }
                return risto;
            }
            if(a == "Q"){
                for(auto& it : recensioni){
                    if(it.second.votoQual >= x) risto.push_back(it.first);
                }
                return risto;
            } 
            if(a == "L"){
                for(auto& it : recensioni){
                    if(it.second.votoLoc >= x) risto.push_back(it.first);
                }
                return risto;
            } 
            if(a == "O"){
                for(auto& it : recensioni){
                    if(it.second.votoOrig >= x) risto.push_back(it.first);
                }
                return risto;
            } 
            return {};
        }
};

struct ristorante{
    string nome;
    string località;
    pair<double, double> coordinate;
};

struct recensione{
    int votoPrezz; 
    int votoQual;
    int votoLoc;
    int votoOrig;

    recensione() : votoPrezz(0), votoQual(0), votoLoc(0), votoOrig(0);
};

