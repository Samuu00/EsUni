#include <iostream>
#include <vector>
using namespace std;

class StatisticheVettore {
    public:
        virtual double Compute(vector<int>){
            return -1;
        };
        virtual ~StatisticheVettore() {}
};
class mediaVettore : public StatisticheVettore{
    public:
        double Compute(vector<int> v) override {
            double media = 0;
            int lenght = v.size();
            for(int i = 0; i < v.size(); i++){
                media += v[i];
            }
            return media/lenght;
        }
};
class ModaVettore : public StatisticheVettore{
    public:
        double Compute(vector<int> v) override {
            int maxVal = v[0];
            for (int num : v) {
                if (num > maxVal) maxVal = num;
            }
            
            vector<int> conteggio(maxVal + 1, 0);
            for (int num : v) {
                conteggio[num]++;
            }
    
            int moda = 0;
            int maxConteggio = conteggio[0];
            for (int i = 1; i <= maxVal; i++) {
                if (conteggio[i] > maxConteggio) {
                    maxConteggio = conteggio[i];
                    moda = i;
                }
            } 
            return moda;
        }
};
class medianaVettore : public StatisticheVettore{
    public:
        double Compute(vector<int> v){

            int lenght = v.size();
            double mediana = v[lenght/2];
            return mediana;
        }
};

int main() {
    vector<int> numeri = {1, 2, 3, 4, 5, 2, 3, 2, 4, 5};
    
    mediaVettore media;
    ModaVettore moda;
    medianaVettore mediana;
   
    cout << "Vettore di numeri: ";
    for(int num : numeri) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Media: " << media.Compute(numeri) << endl;
    cout << "Moda: " << moda.Compute(numeri) << endl;
    cout << "Mediana: " << mediana.Compute(numeri) << endl;
    
    return 0;
}
