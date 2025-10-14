#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

//es2
struct Brano{
    string titolo;
    string artista;
    unsigned durata;

    Brano(string t, string a, unsigned d) : titolo(t), artista(a), durata(d) {};
};

class PlayList{
    private:
        vector<Brano> playList;

    public:
        void aggiungiBrano(Brano& b){
            playList.push_back(b);
        }

        void rimPerTitolo(string tit){
            for(int i = 0; i < playList.size(); i++){
                if(playList[i].titolo == tit){
                    playList.erase(playList.begin() + i);
                }
            }
        }

        unsigned durPlayList(){
            unsigned dur = 0;
            for(Brano b : playList){
                dur += b.durata;
            }
            return dur;
        }

        string branoPiuLungo(){
            string tit = "";
            unsigned maxDur = 0;
            for(int i = 0; i < playList.size(); i++){
                if(playList[i].durata > maxDur){
                    maxDur = playList[i].durata;
                    tit = playList[i].titolo;
                }
            }
            return tit;
        }

        bool operator==(PlayList& other){
            if(playList.size() != other.playList.size()) return false;
            for(int i = 0; i < playList.size(); i++){
                if(playList[i].titolo != other.playList[i].titolo) return false;
                if(playList[i].artista != other.playList[i].artista) return false;
                if(playList[i].durata != other.playList[i].durata) return false;
            }
            return true;
        }
};
class JukeBox{
    private:
        map<string, PlayList> jukeBox;
    
    public:
        void aggiungiPlayList(string nome, PlayList& playList){
            jukeBox[nome] = playList;
        }

        string piuLunga(){
            unsigned durata = 0;
            string nome = "";
            for(auto& it : jukeBox){
                unsigned d = it.second.durPlayList();
                if(d > durata){
                    durata = d;
                    nome = it.first;
                }
            }
            return nome;
        }
};


//es3
struct node{
    int val;
    node* sin;
    node* des;

    node(int v): sin(nullptr), des(nullptr) {};
};

int altAlb(node* root){
    if(root == nullptr) return 0;
    return 1 + max(altAlb(root->sin), altAlb(root->des));
}

bool is_balanced(node* root){
    if(root == nullptr) return false;
    int hSin = altAlb(root->sin);
    int hDes = altAlb(root->des);
    if(abs(hSin - hDes) > 1) return false;
    return is_balanced(root->sin) && is_balanced(root->des);
}


//es4
bool hamiltonian_path(Grafo& grafo, vector<int>& path, set<int>& visitati, int p){
    if(path.size() == grafo.n()) return true;
    visitati.insert(p);
    path.push_back(p);
    for(int v : grafo[p]){
        if(!visitati.count(v)){
            if(hamiltonian_path(grafo, path, visitati, v)) return true;
        }
    }
    path.pop_back();
    visitati.erase(p);
    return false;
}


