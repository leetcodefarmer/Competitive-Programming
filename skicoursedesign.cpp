/* USACO 2014 January Contest, Bronze Problem 1. Ski Course Design http://usaco.org/index.php?page=viewproblem2&cpid=376 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n;
    fin >> n;
    int heights[n];
    for (int i = 0; i < n; i++) {
        fin >> heights[i];
    }
    int answer = 1e9;
    for (int j = 0; j <= 100; j++) {
        int current = 0;
        for (int k = 0; k < n; k++) {
            if (heights[k] > j + 17) {
                current += (heights[k] - j - 17) * (heights[k] - j - 17);
            } else if (heights[k] < j) {
                current += (j - heights[k]) * (j - heights[k]);
            }
        }
        answer = min(answer, current);
    }
    fout << answer << endl;
    return 0;
}