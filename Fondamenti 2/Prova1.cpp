#include <iostream>
#include <vector>
using namespace std;


//es2
class Task{
    private:
        string descr;
        int prior;
    
    public:
        Task(string d, int p) : descr(d), prior(p) {}
        string virtual getDesc(){
            return descr;
        }
        int virtual getPrio(){
            return prior;
        }

        int virtual calcolaCosto() const = 0 {};

        virtual ~Task(){}
};

class TaskSemplice : public Task{
    private:
        int oreStim;
    
    public:
        TaskSemplice(const string& d, int p, int ore) 
        : Task(d, p), oreStim(ore) {}

        int calcolaCosto() override {
            return oreStim;
        }
};

class TaskComplessa : public Task{
    private:
        vector<Task*> tasks;

    public:
        TaskComposto(const string& d, int p) : Task(d, p) {}

        void aggTask(Task* t){
            tasks.push_back(t);
        }

        int calcolaCosto() override {
            int somma = 0;
            for(auto& v : tasks){
                somma += v->calcolaCosto();
            }

            int perc = (somma * 10) / 100;
            return somma + perc;
        }

        ~Task(){
            for(auto& v : tasks){
                delete v;
            }
        }
};

class projectManager {
    private:
        map<string, Task*> project;
    
    public:

        bool addTask(string id, Task* t){
            auto it = project.find(id);
            if(it == project.end()){
                project[id] = t;
                return true;
            }
            return false;
        }

        int getCostoProj() const{
            int tot = 0;
            for(auto& it : project){
                tot += it.second->calcolaCosto();
            }
            return tot;
        }

        vector<Task*> getPrio(int min){
            vector<Task*> minimum;

            for(auto& it : project){
                if(it.second->getPrio() >= min) minimum.push_back(it.second);
            }
            return minimum;
        }

        ~Task(){
            for(auto& it : project){
                delete it.second;
            }
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
                numArchi++;
            }
        }

        bool dfs(int u, int x, int v, vector<bool>& visitati){
            visitati[u] = true;
            if(u == v) return true;

            for(int i = 0; i < n(); i++){
                if(i == x) continue;
                if(adj[u][i] && !visitati[i]){
                    if(dfs(i, x, v, visitati)) return true;
                }
            }
            return false;
        }

        vector<int> trovaPonte(int u, int v){
            vector<int> nodiPonte;

            for(int i = 0; i < n(); i++){
                if(i == u || i == v) continue;
                vector<bool> visitati(n(), false);

                if(!dfs(u, i, v, visitati)) nodiPonte.push_back(i);
            }
            return nodiPonte;
        }
}