/* USACO 2017 US Open Contest, Bronze Problem 2. Bovine Genomics http://www.usaco.org/index.php?page=viewproblem2&cpid=736 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

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

    int spottya = -1;
    int spottyc = -1;
    int spottyg = -1;
    int spottyt = -1;
    int plaina = -1;
    int plainc = -1;
    int plaing = -1;
    int plaint = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 'A') {
                spottya = 1;
            }
            if (a[j][i] == 'C') {
                spottyc = 1;
            }
            if (a[j][i] == 'G') {
                spottyg = 1;
            }
            if (a[j][i] == 'T') {
                spottyt = 1;
            }
            if (b[j][i] == 'A') {
                plaina = 1;
            }
            if (b[j][i] == 'C') {
                plainc = 1;
            }
            if (b[j][i] == 'G') {
                plaing = 1;
            }
            if (b[j][i] == 'T') {
                plaint = 1;
            }
        }
        if (spottya + plaina <= 0 && spottyc + plainc <= 0 && spottyg + plaing <= 0 && spottyt + plaint <= 0) {
            totalpositions++;
        }
        spottya = -1;
        spottyc = -1;
        spottyg = -1;
        spottyt = -1;
        plaina = -1;
        plainc = -1;
        plaing = -1;
        plaint = -1;
    }
    fout << totalpositions << endl;
    return 0;
}