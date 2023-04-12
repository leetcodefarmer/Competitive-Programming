/* USACO 2015 February Contest, Bronze Problem 1. Censoring (Bronze) http://www.usaco.org/index.php?page=viewproblem2&cpid=526 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("censor.out");
    ifstream fin ("censor.in");
    string S, T;
    fin >> S >> T;
    string newS = "";
    for (int i = 0; i < S.length(); i++) {
        newS += S.substr(i, 1);
        if (newS.length() >= T.length() && newS.substr(newS.length() - T.length()) == T) {
            newS.erase(newS.length() - T.length());
        }
    }
    fout << newS << endl;
    return 0;
}