/* USACO 2020 January Contest, Bronze Problem 1. Word Processor http://usaco.org/index.php?page=viewproblem2&cpid=987 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    int n, k;
    fin >> n >> k;
    int counter = 0;
    string s = "";
    string swithspaces = "";
    for (int i = 0; i < n; i++) {
        string temp;
        fin >> temp;
        if (temp.length() + s.length() > k) {
            fout << swithspaces << endl;
            s = temp;
            swithspaces = temp;
        } else if (i == 0) {
            s += temp;
            swithspaces += temp;
        } else {
            s += temp;
            swithspaces += " " + temp;
        }
        if (i == n - 1) {
            fout << swithspaces << endl;
        }
    }
    return 0;
}