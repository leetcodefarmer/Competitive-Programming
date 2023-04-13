/* USACO 2017 December Contest, Bronze Problem 3. Milk Measurement http://www.usaco.org/index.php?page=viewproblem2&cpid=761 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

int howmuchmilk[3][101] = {};
int howmuchmilktoadd[3][101] = {};

bool ismax(int d, int e, int f) {
    return d == max(max(d, e), f);
}

int main() {
    ofstream fout ("measurement.out");
    ifstream fin ("measurement.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        fin >> a;
        string s;
        fin >> s;
        int b;
        fin >> b;
        if (s == "Bessie") {
            howmuchmilktoadd[0][a] = b;
        }
        else if (s == "Elsie") {
            howmuchmilktoadd[1][a] = b;
        }
        else if (s == "Mildred") {
            howmuchmilktoadd[2][a] = b;
        }
    }
    howmuchmilk[0][0] = 7;
    howmuchmilk[1][0] = 7;
    howmuchmilk[2][0] = 7;
    int counter = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < 3; j++) {
            howmuchmilk[j][i] = howmuchmilk[j][i - 1] + howmuchmilktoadd[j][i];
        }
        if (ismax(howmuchmilk[0][i], howmuchmilk[1][i], howmuchmilk[2][i]) != ismax(howmuchmilk[0][i - 1], howmuchmilk[1][i - 1], howmuchmilk[2][i - 1]) || ismax(howmuchmilk[1][i], howmuchmilk[2][i], howmuchmilk[0][i]) != ismax(howmuchmilk[1][i - 1], howmuchmilk[2][i - 1], howmuchmilk[0][i - 1]) || ismax(howmuchmilk[2][i], howmuchmilk[0][i], howmuchmilk[1][i]) != ismax(howmuchmilk[2][i - 1], howmuchmilk[0][i - 1], howmuchmilk[1][i - 1])) {
            counter++;
        }
    }
    fout << counter << endl;
    return 0;
}