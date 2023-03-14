/* USACO 2016 US Open Contest, Bronze Problem 1. Diamond Collector http://www.usaco.org/index.php?page=viewproblem2&cpid=639 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("diamond.out");
    ifstream fin ("diamond.in");
    int n, k;
    fin >> n >> k;
    int diamondarray[n];
    for (int i = 0; i < n; i++) {
        fin >> diamondarray[i];
    }
    std::sort(diamondarray, diamondarray + n);
    int runningmax = 1;
    for (int j = 0; j < n; j++) {
        int index = 1;
        for (int l = j + 1; l < n; l++) {
            if (abs(diamondarray[j] - diamondarray[l]) <= k) {
                index += 1;
            } else {
                break;
            }
            runningmax = max(runningmax, index);
        }
    }
    fout << runningmax << endl;
    return 0;
}