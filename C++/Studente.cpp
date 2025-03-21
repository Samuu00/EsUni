#include <iostream>
using namespace std;

class Student{
    private:
        string first_name, last_name;
        int age, standard;
    public:
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        int get_age(){
            return age;
        }
        int get_standard(){
            return standard;
        }
        void set_first_name(string f){
            first_name = f;
        }
        void set_last_name(string l){
            last_name = l;
        }
        void set_age(int a){
            age = a;
        }
        void set_standard(int s){
            standard = s;
        }
};
int main() {
    int a, s;
    string f, l;
    
    cin >> a >> f >> l >> s;

    Student st;
    st.set_age(a);
    st.set_standard(s);
    st.set_first_name(f);
    st.set_last_name(l);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.get_age() << "," << st.get_first_name() << ","<< st.get_last_name() << ","<< st.get_standard() << "\n";
    
    return 0;
}
