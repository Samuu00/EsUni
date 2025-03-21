#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class CalcolaFrequenze {
private:
    string testo;
public:
    CalcolaFrequenze(){
        testo = "";
    }
    CalcolaFrequenze(const CalcolaFrequenze& cf){
        testo = cf.testo;
    }
    CalcolaFrequenze(string t){
        testo = t;
    }

    void leggiTesto(const string& s) {
        testo += s; 
    }

    string getTesto() const {
        return testo;
    }

    vector<char> top(int k) const {
        unordered_map<char, int> freq;
        
        for (char c : testo) {
            freq[c]++;
        }
        //cazzo pene culo c++ MERDA VIVA IL DUCE
        vector<pair<char, int>> freq_vec(freq.begin(), freq.end());
        
        sort(freq_vec.begin(), freq_vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;  
        });

        vector<char> result;
        for (size_t i = 0; i < k && i < freq_vec.size(); i++) {
            result.push_back(freq_vec[i].first);
        }
        
        return result;
    }

    virtual double frequenza(char c) const {
        double cont = 0;
        for (char i : testo) {
            if (i == c) {
                cont++;
            }
        }
        if (cont > 0) {
            return cont;
        } else {
            cout << "Nessuna occorrenza di quel carattere, riprova" << endl;
            return 0.0;
        }
    }

    virtual ~CalcolaFrequenze() {} 
};

class CalcolaFrequenzeRelative : public CalcolaFrequenze {
public:
    double frequenza(char c) {
        double cont = 0;
        int current_length = 0;
        for (char i : getTesto()) {
            current_length++;
            if (i == c) {
                cont++;
            }
        }
        if (cont > 0) {
            return cont / current_length;
        } else {
            cout << "Nessuna occorrenza di quel carattere, riprova" << endl;
            return 0.0; 
        }
    }
};

int main() {
    string s;
    cout << "Inserisci testo: ";
    cin >> s;

    CalcolaFrequenze cf;
    CalcolaFrequenzeRelative cfr;

    cf.leggiTesto(s);
    cfr.leggiTesto(s);

    int k;
    cout << "Inserisci numero k: ";
    cin >> k;
    
    vector<char> top_chars = cf.top(k);
    cout << "Vettore con " << k << " caratteri piu frequenti: ";
    for (char c : top_chars) {
        cout << c << " ";
    }
    cout << endl;

    char c;
    cout << "Inserisci carattere di cui vuoi sapere la frequenza e la frequenza relativa: ";
    cin >> c;
    cout << "Frequenza di " << c << ": " << cf.frequenza(c) << endl;
    cout << "Frequenza relativa di " << c << ": " << cfr.frequenza(c) << endl;

    return 0;
}