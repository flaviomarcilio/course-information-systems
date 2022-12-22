#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0, c = 0, part = 0, diamantes = 0;
    cin >> n;
    c = getchar();
    while (n > 0) {
        do {
            c = getchar();
            if (c == 60) {
                part++;
            } else if (c == 62 && part > 0) {
                diamantes++;
                part--;
            }
        } while (c != '\n');
        cout << diamantes << endl;
        diamantes = 0;
        part = 0;
        n--;
    }
    return 0;
}
