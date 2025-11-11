#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

//es2
class Tweet{
    private:
        int id;
        string testo;
        string autore;

    
    public:
        Tweet(int i, string t, string aut): id(i), testo(t), autore(aut) {}

        int getId(){ return id; }
        string getTesto(){ return testo; }
        string getAutore(){ return autore; }

        vector<string> getHashtag() const { 
            vector<string> hashTag;
            
            stringstream ss(testo); 
            string parola;

            while (ss >> parola) { 
                
                if (parola.length() > 1 && parola[0] == '#') {
                    hashTag.push_back(parola.substr(1)); 
                }
            }
            
            return hashTag;
        }
};

class TweetManager{
    private:
        map<int, Tweet*> tweets_by_id;
        map<string, vector<Tweet*>> tweets_by_user;
        map<string, vector<Tweet*>> tweets_by_hashtag;

    public:
        TweetManager(){}

        ~TweetManager(){
            for(auto& it : tweets_by_id){
                delete it.second;
            }
        }

        bool postaTweet(int id, const string& testo, const string& autore){
            auto it = tweets_by_id.find(id);
            if(it != tweets_by_id.end()) return false;

            Tweet* t = new Tweet(id, testo, autore);

            tweets_by_id[id] = t;
            tweets_by_user[autore].emplace_back(t);
            vector<string> hashT = t.getHashtag();
            for(string s : hashT){
                tweets_by_hashtag[s].emplace_back(t);
            }

            return true;
        }

        vector<Tweet*> getTimeLineUtente(const string& autore) const {
            auto it = tweets_by_user.find(autore);
            
            if(it != tweets_by_user.end()){

                vector<Tweet*> tweets;
                for(auto& p : it.second){
                    tweets.push_back(p);
                }

                return tweets;
            }

            return {}
        }

        vector<Tweet*> cercaHashtag(const string& hashtag) const {
            auto it = tweets_by_hashtag.find(hashtag);

            if(it != tweets_by_hashtag.end()){

                vector<Tweet*> tweetsHash;
                for(auto& p : it.second){
                    tweetsHash.push_back(p);
                }

                return tweetsHash;
            }

            return {}
        }

};


//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        int info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(int valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

        ~AlberoB() {
            delete sx; 
            delete dx;
        }

        AlberoB* figlio(Direzione dir) {
            if (dir == SIN) {
                return this->sx;
            }
            return this->dx;
        }

        AlberoB* padre() {
            return this->p;
        }

        int radice() {
            return this->info;
        }

        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a) {
            return a == nullptr;
        }

        void sommaPath(AlberoB* a, int s, vector<int>& sum){
            if(nullo(a)) return;

            s += a.radice();
            
            if(a.foglia()) sum.push_back(s);

            sommaPath(a.figlio(SIN), s, sum);
            sommaPath(a.figlio(DES), s, sum);
        }

        int maxPathSum(AlberoB* a){
            int s = 0;
            vector<int> sum;

            sommaPath(a, s, sum);

            if(sum.size() > 0){
                sort(sum.begin(), sum.end());
                return sum[sum.size() - 1];
            }
            return -1;
        }
};