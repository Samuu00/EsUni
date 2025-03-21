#include <iostream>
#include <vector>
#include <string>
using namespace std;

class File{
    public:
        virtual void leggiContenuto() = 0;
        virtual string getTipo() = 0;
        virtual ~File() {}
};

class FileTesto : public virtual File{
    private:
        string tipo, testo;
    public:
        FileTesto() : File(){
            tipo = "testo";
            testo = "";
        }
        FileTesto(FileTesto& ft): File(ft){
            testo = ft.testo;
        }
        FileTesto(string t) : File(){
            testo = t;
        }

        void leggiContenuto() override {
            string t;
            cout<<"Inserisci testo: ";
            cin>> t;
            testo = t; 
        }
        string getTipo() override {
            cout<<"Il file di testo contiene: " << testo <<endl;
        }
};

class FileBinario : public virtual File{
    private:
        vector<int> numeri;
    public:
        void leggiContenuto() override {
            int c, d;
            cout<<"Inserire quanti numeri deve avere il file binario: ";
            cin>> d;
            for(size_t i = 0; i < d; i++){
                cin>> c;
                numeri.push_back(c);
            }
        }
        string getTipo() override {
            string result = "Il file binario contiene: ";
            for (size_t i = 0; i < numeri.size(); i++) {
                result += to_string(numeri[i]);
            }
            cout<<result<<endl;
        }
        
};

int main(){
    vector<File*> file;
    int n;
    cout<<"Inserisci quanti file aggiungere: ";
    cin>> n;
    for(int i = 0; i < n; i++){
        string t;
        cout<<"Inserisci tipo di file da inserie(testo/binario): " <<endl;
        cin>> t;
        if(t == "testo"){
            file.push_back(new FileTesto());
        }
        else if(t == "binario"){
            file.push_back(new FileBinario());
        }
    }
    for(int i = 0; i < n; i++){
        file[i]->leggiContenuto();
    }
    for(int i = 0; i < n; i++){
        file[i]->getTipo();
    }
    for(int i = 0; i < n; i++){
        delete file[i];
    }
}