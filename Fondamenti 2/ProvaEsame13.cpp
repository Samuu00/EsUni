#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


//es1
class StackIntelligente{
    private:
        int maxSize;
        int size;
        int* arr;
    public:
        StackIntelligente(){
            this->maxSize = 100;
            this->size = 0;
            this->arr = new int[this->maxSize];
        }
        ~StackIntelligente(){
            delete[] this->arr;
        };
        void push(int valore){
            int* nuovoArr = new int[size + 1];
            nuovoArr[0] = valore;  
        
            for (int i = 0; i < size; i++) {
                nuovoArr[i + 1] = arr[i];
            }
        
            delete[] arr;     
            arr = nuovoArr;    
            size += 1;        
        }
        void pop(){
            int* nuovoArr = new int[size - 1];
            for(int i = 1; i < size; i++){
                nuovoArr[i] = arr[i];
            }
            delete[] arr;
            arr = nuovoArr;
            size -= 1;
        }
        int top(){
            return arr[0];
        }
        void rimuovi(int x){
            int daRim = 0;
            for(int i = size - 1; i >= 0; i--){
                if(arr[i] == x){
                    daRim = i;
                }
            }
            for(int i = daRim; i < size - 1; i++){
                arr[i] = arr[i + 1];
            }
            size -= 1;
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
        bool verificaCammino(int u, vector<int>& s, vector<int>& t, vector<bool>& visitato, unordered_set<int>& t_set, unordered_set<int>& s_set){
            if(t_set.count(u)) return false;
            if(u == n) return false;
            visitato[u] = true;
            for(int vicino : grafo[u]){
                if(visitato[vicino]) continue;
                if(s_set.count(vicino)) return true;
                if(verificaCammino(vicino, s, t, visitato, t_set, s_set)) return true;
            }
            visitato[u] = false;
            return false;
        }
};


//es3
bool bilancia(const vector<int>& abilita, int d) {
    int length = abilita.size();
    vector<int> somme;
    int somma = 0;
    for(int i = 0; i < length / 2; i++){
        somma += abilita[i];
    }
    somme.push_back(somma);
    somma = 0;
    for(int i = length / 2; i < length; i++){
        somma += abilita[i];
    }
    somme.push_back(somma);
    if(abs(somme[0] - somme[1]) <= d) return true;
    return false;
}


int main(){
    vector<int> abilita = {6, 2, 3, 5};
    int d = 2;
    if(bilancia(abilita, d)){
        cout << "Bilanciato";
    }else{
        cout << "Non bilanciato";
    }
}