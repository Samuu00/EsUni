#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Box {
private:
    int length, breadth, height;
public:
    Box() : length(0), breadth(0), height(0) {}
    
    Box(Box& temp) {
        length = temp.length;
        breadth = temp.breadth;
        height = temp.height;
    }
    
    Box(int l, int b, int h) {
        length = l;
        breadth = b;
        height = h;
    }
    
    int getLength() {
        return length;
    }
    int getBreadth() {
        return breadth;
    }
    int getHeight() {
        return height;
    }
    
    void setLength(int l) {
        length = l;
    }
    void setBreadth(int b) {
        breadth = b;
    }
    void setHeight(int h) {
        height = h;
    }
    
    long long CalculateVolume() {
        return (long long)length * breadth * height;
    }
    friend ostream& operator<<(ostream& out, Box& box) {
        out << "Length: " << box.length << ", Breadth: " << box.breadth << ", Height: " << box.height;
        return out;
    }
    bool operator<(Box& other) {
        return CalculateVolume() < other.CalculateVolume();
    }
};

void check2() {
    int n;
    cin >> n;
    Box temp;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            cout << temp << endl;
        }
        else if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        else if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser\n";
            }
            else {
                cout << "Greater\n";
            }
        }
        else if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        else if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main() {
    check2();
    return 0;
}