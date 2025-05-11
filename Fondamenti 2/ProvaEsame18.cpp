#include <iostream>
using namespace std;


//es1
struct contatto{
    string nome;
    int numero;
};

class RubricaTelefonica{
    private:
        int maxSize;
        int size;
        contatto* rubrica;
    public:
        RubricaTelefonica(){
            this->maxSize = 100;
            this->size = 0;
            this->rubrica = new contatto[this->maxSize];
        }
        ~RubricaTelefonica(){
            delete[] rubrica;
        }
        void aggiungi(string& nom, int& num){
            if(size == 0){
                rubrica[0].nome = nom;
                rubrica[0].numero = num;
                size++;
                return;
            }
            for(int i = 0; i < size; i++){
                if(rubrica[i].nome == nom && rubrica[i].numero == num){
                    cout<< "numero esistente";
                    return;
                }
            }
            rubrica[size].nome = nom;
            rubrica[size].numero = num;
            size++;
        }
        void modifica(string& nom, int& num, int& nuovoNumero){
            for(int i = 0; i < size; i++){
                if(rubrica[i].nome == nom && rubrica[i].numero == num){
                    rubrica[i].numero = nuovoNumero;
                }
            }
        }
        string numero(string& nom, int& num){
            string strNum = "";
            for(int i = 0; i < size; i++){
                if(rubrica[i].nome == nom && rubrica[i].numero == num){
                    strNum = rubrica[i].numero.to_string();
                    return strNum;
                }   
            }
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v): val(v), sinistro(nullptr), destro(nullptr){}
};

int contaFoglieValore(nodo* root, int& valore){
    if(root == nullptr) return 0;

    if(root->sinistro == nullptr && root->destro == nullptr){
        if(root->val == valore) return 1;
        return 0;
    }

    return contaFoglieValore(root->sinistro, valore) + contaFoglieValore(root->destro, valore);
}


//es3
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;
    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }
        bool connessiFinoA(int s, int t, int maxNodi, vector<bool>& visitato, int& cont){
            if(cont > maxNodi) return false;
            if(s == t) return true;
            visitato[s] = true;
            cont++;
            for(int v : grafo[s]){
                if(visitato[v]) continue;
                if(connessiFinoA(v, t, maxNodi, visitato)) return true;
            }
            visitato[s] = false;
            cont--;
            return false;
        }
};