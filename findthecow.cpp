/* USACO 2012 November Contest, Bronze Problem 1. Find the Cow! http://www.usaco.org/index.php?page=viewproblem2&cpid=187 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int leftarray[50000] = {};
int rightarray[50000] = {};

int main() {
    ofstream fout ("cowfind.out");
    ifstream fin ("cowfind.in");
    string s;
    fin >> s;
    if (s.length() <= 3) {
        fout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (s.substr(i, 2) == "((") {
            leftarray[i]++;
        }
        if (s.substr(i, 2) == "))") {
            rightarray[i]++;
        }
    }
    int counter = 0;
    for (int i = 0; i < s.length() - 2; i++) {
        if (leftarray[i] == 1) {
            for (int j = i + 2; j < s.length() - 1; j++) {
                if (rightarray[j] == 1) {
                    counter++;
                }
            }
        }
    }
    fout << counter << endl;
    return 0;
}