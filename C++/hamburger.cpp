#include <iostream>
using namespace std;

int main() {
    int numHamburgers; 
    cin >> numHamburgers;

    int totalCookingTime = 0; 
    int oilTemperature; 

    while (numHamburgers > 0) {
        cin >> oilTemperature;

        int cookingTime;
        if (oilTemperature > 180) {
            cookingTime = 10;
        } else if (oilTemperature >= 160 || oilTemperature <= 180) {
            cookingTime = 12;
        } else if (oilTemperature < 180) {
            cookingTime = 15;
        }

        
        int batchSize = min(numHamburgers, 6);
        totalCookingTime += cookingTime;
        numHamburgers -= batchSize;
    }

    cout << totalCookingTime <<endl;
    return 0;
}