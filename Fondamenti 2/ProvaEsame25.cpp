#include <iostream>
#include <vector>
using namespace std;


//es1
struct Brano{
    string titolo;
    string artista;
    int durata;
    string genere;
};

class PlayList{
    private:
        vector<Brano> playlist;
    public:
        void aggiungiBrano(Brano& b){
            playlist.push_back(b);
        }
        void rimuoviBrano(string& genere){
            int minDurata = 0;
            int minIndex = 0;
            for(int i = 0; i < playlist.size(); i++){
                if(playlist[i].genere == genere){
                    if(playlist[i].durata < minDurata){
                        minDurata = playlist[i].durata;
                        minIndex = i;
                    }
                }
            }
            playlist.erase(playlist.begin() + minIndex);
        }

        int durata(){
            int durataMax = 0;
            for(int i = 0; i < playlist.size(); i++){
                durataMax += playlist[i].durata;
            }
            return durataMax;
        }
};


//es2
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;

    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }

        bool esisteCamminoLungoK(int p, int a, int k, vector<bool>& visitato){
            if(p == a && k == 0) return true;
            visitato[u] = true;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                if(esisteCamminoLungoK(v, a, k - 1, visitato)) return true;
            }
            visitato[p] = false;
            return false;
        }
};