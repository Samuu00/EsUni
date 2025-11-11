#include <iostream>
using namespace std;

//es2
class Deque {
    private:
        int* buffer;    
        int capacita;   
        int size;       
        int head;       
        int tail;       

        void resize(){
            if(size == capacita){

                int newSize = this->capacita * 2;

                int* newBuffer = new int[newSize];
                for(int i = 0; i < size(); i++){
                    
                    int oldIndex = (head + i) %  capacita;
                    newBuffer[i] = buffer[oldIndex];
                }

                delete[] buffer;
                buffer = newBuffer;
                head = 0; 
                tail = size;
                this->capacita = newSize;
            }
        }

    public:
        Deque(): capacita(100), size(0), head(0), tail(0){
            this->buffer = new int[this->capacita];
        }
        
        ~Deque(){
            delete[] buffer;
        }
        
        void push_front(int valore){
            if(size == capacita) resize();

            head = (head - 1 + capacita) % capacita;
            buffer[head] = valore;
            size++;
        }
        
        void push_back(int valore){
            if(size == capacita) resize();

            buffer[tail] = valore;
            tail = (tail + 1) % capacita;
            size++;
        }
        
        int pop_front(){
            int ret = buffer[head];

            head = (head + 1) % capacita;
            size--;
            return ret;
        }
        
        int pop_back(){
            int ret = buffer[tail];

            tail = (tail - 1) % capacita;
            size--;
            return ret;
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
        vector<vector<int>> adj;

    public:
        Grafo(int n, vector<int> p) : numNodi(n), numArchi(0), adj(n, vector<int>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j, int p) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = p;
                adj[j][i] = p;
                numArchi++;
            }
        }

    int trovaCamminoMaxMin(const Grafo& g, int u, int v) {
        int n = g.n();
        vector<int> bottleneck(n, -1); 

        priority_queue<pair<int, int>> pq;

    
        bottleneck[u] = INT_MAX;
        pq.push({INT_MAX, u});

        while (!pq.empty()) {
          
            int current_bottleneck = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            if (curr_node == v) {
                return current_bottleneck;
            }

            if (current_bottleneck < bottleneck[curr_node]) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (g(curr_node, i)) { 
                    int edge_weight = g.peso(curr_node, i);

                    int new_bottleneck = min(current_bottleneck, edge_weight);

                    if (new_bottleneck > bottleneck[i]) {
                        bottleneck[i] = new_bottleneck;
                        pq.push({new_bottleneck, i});
                    }
                }
            }
        }
        return -1;
    }
}