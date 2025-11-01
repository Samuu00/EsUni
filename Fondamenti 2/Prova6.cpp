#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//es2
class MinMaxStack {
    private:
        int* data;
        int* minData; 
        int* maxData; 
        int size;
        int capacita;

        void resize(){
            if(size == capacita){
                int newSize = size * 2;
                this->capacita = newSize;

                int* newData = new int[newSize];
                int* newMin = new int[newSize];
                int* newMax = new int[newSize];
                for(int i = 0; i < size; i++){
                    newData[i] = data[i];
                    newMin[i] = minData[i];
                    newMax[i] = maxData[i];
                }

                delete[] data;
                delete[] minData;
                delete[] maxData;
                data = newData;
                minData = newMin;
                maxData = newMax;
            }
        }; 

    public:
        MinMaxStack(): size(0), capacita(100){
            this->data = new int[this->capacita];
            this->minData = new int[this->capacita];
            this->maxData = new int[this->capacita];
        }
        
        ~MinMaxStack() {
            delete[] maxData;
            delete[] minData;
            delete[] data;
        }
        
        void push(int valore){
            if(size == capacita) resize();

            data[size] = valore;

            if(empty()){
                minData[size] = valore;
                maxData[size] = valore;
                size++;
            }else{
                minData[size] = min(valore, minData[size - 1]);
                maxData[size] = max(valore, maxData[size - 1]);
            }
        }

        void pop(){
            size--;
        }
        
        int top() const{
            return data[size - 1];
        }
        
        int getMin() const{
            return minData[size - 1];
        }
        
        int getMax() const{
            return maxData[size - 1];
        }
        
        bool empty() const{
            return size == 0;
        }
};

//es3
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n, vector<int> p) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = true;
                adj[j][i] = true;
                numArchi++;
            }
        }

        int calcolaEccentricita(){
            queue<int> q;
            vector<bool> visitati(n(), false);
            vector<int> dist(n(), INT_MAX);

            q.push(n);
            dist[n] = 0;
            visitati[n] = true;
            
            while(!q.empty()){

                int curr = q.front(); q.pop();

                for(int i = 0; i < n(); i++){
                    if(adj[curr][i] && !visitati[i] && i != n){
                        visitati[i] = true;
                        dist[i] = dist[curr] + 1;
                        q.push(i);
                    }
                }
            }
            int ecc = -1;
            for(int m : dist){
                if(m == INT_MAX) return INT_MAX;
                ecc = max(ecc, m);
            }
            return ecc;
        }

        int findRaggio(){
            vector<int> eccNode;

            for(int i = 0; i < n(); i++){

                int r = calcolaEccentricita(i);

                if(r != INT_MAX) eccNode.push_back(r);
            }
            int ragg = INT_MAX;
            for(int m : eccNode){
                if(m < ragg) ragg = m;
            }
            return ragg;
        }

        vector<int> findCenter(){
            vector<int> center;
            int r = findRaggio();
            for(int i = 0; i < n(); i++){
                int ecc = calcolaEccentricita(i);

                if(ecc == r) center.push_back(i);
            }
            return center;
        }
};