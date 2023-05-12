/* USACO 2017 US Open Contest, Silver Problem 2. Bovine Genomics http://www.usaco.org/index.php?page=viewproblem2&cpid=739 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

int main() {
    ofstream fout ("cownomics.out");
    ifstream fin ("cownomics.in");
    int n, m;
    fin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    string b[n];
    for (int i = 0; i < n; i++) {
        fin >> b[i];
    }
    int totalpositions = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                unordered_set<string> triplets;
                for (int cow = 0; cow < n; cow++) {
                    string d = a[cow].substr(i, 1) + a[cow].substr(j, 1) + a[cow].substr(k, 1);
                    triplets.insert(d);
                }
                for (int cow = 0; cow < n; cow++) {
                    string e = b[cow].substr(i, 1) + b[cow].substr(j, 1) + b[cow].substr(k, 1);
                    if (triplets.count(e) > 0) {
                        break;
                    }
                    if (cow == n - 1) {
                        totalpositions++;
                    }
                }
            }
        }
    }
    fout << totalpositions << endl;
    return 0;
}