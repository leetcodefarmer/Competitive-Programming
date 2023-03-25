/* USACO 2012 December Contest, Bronze Problem 1. Meet and Greet http://www.usaco.org/index.php?page=viewproblem2&cpid=205 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int a[1000001] = {};
int b[1000001] = {};

int main() {
    ofstream fout ("greetings.out");
    ifstream fin ("greetings.in");
    int x, y;
    fin >> x >> y;
    int acounter = 1;
    int bcounter = 1;
    for (int i = 0; i < x; i++) {
        int c;
        string d;
        fin >> c >> d;
        if (d == "L") {
            for (int j = 0; j < c; j++) {
                a[acounter] = a[acounter - 1] - 1;
                acounter++;
            }
        } else {
            for (int j = 0; j < c; j++) {
                a[acounter] = a[acounter - 1] + 1;
                acounter++;
            }
        }
    }
    for (int i = 0; i < y; i++) {
        int c;
        string d;
        fin >> c >> d;
        if (d == "L") {
            for (int j = 0; j < c; j++) {
                b[bcounter] = b[bcounter - 1] - 1;
                bcounter++;
            }
        } else {
            for (int j = 0; j < c; j++) {
                b[bcounter] = b[bcounter - 1] + 1;
                bcounter++;
            }
        }
    }
    if (acounter > bcounter) {
        for (int i = bcounter; i <= acounter - 1; i++) {
            b[bcounter] = b[bcounter - 1];
            bcounter++;
        }
    } else if (bcounter > acounter) {
        for (int i = acounter; i <= bcounter - 1; i++) {
            a[acounter] = a[acounter - 1];
            acounter++;
        }
    }
    int counter = 0;
    for (int i = 1; i <= min(acounter - 1, bcounter - 1); i++) {
        if (a[i - 1] != b[i - 1] && a[i] == b[i]) {
            counter++;
        }
    }
    fout << counter << endl;
    return 0;
}