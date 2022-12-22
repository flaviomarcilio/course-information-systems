#include <iostream>
#include <string>
#include <math.h>
 
using namespace std;
 
int main() {
 
    string line;
    string grito = "caw";
    int i, j, number = 0;

    while (cin >> line) {
        if (!grito.compare(line)) {
            cout << number << endl;
            cin >> line;
            number = 0;
        } else {
            j = 2;
            for (i = 0; i < 3; i++) {
                if (line[i] == '*') {
                    number += pow(2, j);
                    j--;
                } else {
                    j--;
                }
            }
        }
    }
 
    return 0;
}