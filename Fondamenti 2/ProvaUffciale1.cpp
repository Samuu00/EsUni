#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


//es1
class webPage{
    private:
        string titolo;
        string testo;
        vector<webPage*> links;
    
    public:
        webPage(const string tit, const string test, vector<string> lk) : titolo(tit), testo(test), links(lk){}

        string getTitolo() const{
            return titolo;
        }

        string getTesto() const{
            return testo;
        }

        vector<webPage*> getLinks() const{
            return links;
        }

        bool operator==(const webPage& other) const{
            return titolo == other.titolo;
        }

        void addLink(webPage& link){
            links.push_back(link);
        }
    
};
class webSite{
    private:
        webPage* home;
        vector<webPage*> pagine;
    
    public:
        webSite(webPage* home) : home(home){
            pagine.push_back(home);
        }

        int find_webPage(const webPage& target) const{
            unordered_map<webPage*, int> distanze;
            queue<webPage*> q;

            for(auto& page : pagine){
                distanze[page] = -1;
            }

            distanze[home] = 0;
            q.push(home);
     
            while(!q.empty()){
                webPage* currentPage = q.front();
                q.pop();

                if(currentPage == &target){
                    return distanze[currentPage];
                }

                for(auto& link : currentPage->getLinks()){
                    if(distanze[link] == -1){
                        distanze[link] = distanze[currentPage] + 1;
                        q.push(link);
                    }
                }
            }
            return -1;
        }
};


//es2
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;
    
    public:
        Grafo(int n){
            this->n = n;
            grafo.resize(n);
        }

        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }

        bool f(Grafo& g){
            vector<int> inDegree(n, 0);
            int totArchi = 0;

            for(int i = 0; i < n; i++){
                for(int j : g.grafo[i]){
                    if(i == j) return false;
                }
                inDegree[j]++;
                totArchi++;
            }
        

            int nodoConAlMassUno = 0;
            for(int i = 0; i < n; i++){
                if(inDegree[i] <= 1){
                    nodoConAlMassUno++;
                }
            }

            for(int i = 0; i < n; i++){
                if((int)grafo[i].size() >= nodoConAlMassUno){
                    return false;
                }
            }

            if(totArchi % 2 != 0) return false;

            return true;

        }

};