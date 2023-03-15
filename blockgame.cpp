/* USACO 2016 December Contest, Bronze Problem 2. Block Game http://www.usaco.org/index.php?page=viewproblem2&cpid=664 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int finalalphabet[26] = {};
int tempalphabet1[26] = {};
int tempalphabet2[26] = {};

int main() {
    ofstream fout ("blocks.out");
    ifstream fin ("blocks.in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        std::fill(tempalphabet1, tempalphabet1 + 26, 0);
        std::fill(tempalphabet2, tempalphabet2 + 26, 0);
        string a, b;
        fin >> a >> b;
        for (int j = 0; j < a.length(); j++) {
            int swapper = int(a[j]) - 97;
            tempalphabet1[swapper]++;
        }
        for (int k = 0; k < b.length(); k++) {
            int swapper = int(b[k]) - 97;
            tempalphabet2[swapper]++;
        }
        for (int l = 0; l < 26; l++) {
            finalalphabet[l] += max(tempalphabet1[l], tempalphabet2[l]);
        }
    }
    for (int m = 0; m < 26; m++) {
        fout << finalalphabet[m] << endl;
    }
    return 0;
}