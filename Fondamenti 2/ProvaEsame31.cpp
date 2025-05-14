#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <map>
using namespace std;


//es1
class videogioco{
    private:
        string nome;
        int annoPubb;
        double prezzo;
        string genere;
        vector<string> console;
    
    public:
        videogioco(const string& n, int anPub, double prezz, const string& gen, const vector<string>& cons){
            nome = n;
            annoPubb = anPub;
            prezzo = prezz;
            genere = gen;
            console = cons;
        }
        string getNome() const {
            return nome;
        }
        int getAnnoPubb() {
            return annoPubb;
        }
        double getPrezzo() {
            return prezzo;
        }
        string getGenere() const{
            return genere;
        }
        vector<string> getConsole() const {
            return console;
        }

        void setPrezzo(double& s){
            if(s >= prezzo){
                throw invalid_argument("Il prezzo non può essere maggiore a quello attuale");
            }else{
                prezzo = s;
            }
        }
};
class catalogoVideogiochi{
    private:
        const string consoleCatalogo;
        vector<videogioco> catalogo;

    public:
        catalogoVideogiochi(const string& v){
            consoleCatalogo = v;
        }
        void aggiungiVideogioco(videogioco& v){
            for(string c : v.getConsole()){
                if(c == consoleCatalogo){
                    catalogo.push_back(v);
                    break;
                }
            }
            ordinaPerAnno();
        }
        void ordinaPerAnno(){
            sort(catalogo.begin(), catalogo.end(), [](const videogioco& a, const videogioco& b){
                if(a.annoPubb != b.annoPubb){
                    return a.annoPubb > b.annoPubb;
                }else{
                    return a.prezzo > b.prezzo;
                }
            });
        }

        videogioco consigliaVideoGioco(int& budget){
            for(videogioco v : catalogo){
                if(int(v.getPrezzo()) <= budget){
                    return v;
                } 
            }
            return videogioco("ERRORE", "", "", 0, 0, {});
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void compaionoNumDispari(nodo* root, const vector<int>& s, map<int, int>& freq){
    if(root == nullptr) return;

    if(find(s.begin(), s.end(), root->val) != s.end()){
        freq[root->val]++;
    }

    compaionoNumDispari(root->sinistro, s, freq);
    compaionoNumDispari(root->destro, s, freq);
}

vector<int> getDispari(nodo* root, const vector<int>& s){
    map<int, int> freq;
    compaionoNumDispari(root, s, freq);
    vector<int> result;
    for(auto& [k, v] : freq){
        if(v % 2 != 0) result.push_back(k);
    }
    return result;
}
