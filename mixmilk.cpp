/* USACO 2018 December Contest, Bronze Problem 1. Mixing Milk http://www.usaco.org/index.php?page=viewproblem2&cpid=855 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int keeptrack[101][3] = {};

int main() {
    ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");
    int bucketcapacity[3] = {};
    fin >> bucketcapacity[0] >> keeptrack[0][0];
    fin >> bucketcapacity[1] >> keeptrack[0][1];
    fin >> bucketcapacity[2] >> keeptrack[0][2];
    for (int i = 0; i < 100; i++) {
        keeptrack[i + 1][i % 3] = max(0, keeptrack[i][i % 3] + keeptrack[i][(i + 1) % 3] - bucketcapacity[(i + 1) % 3]);
        keeptrack[i + 1][(i + 1) % 3] = min(keeptrack[i][i % 3] + keeptrack[i][(i + 1) % 3], bucketcapacity[(i + 1) % 3]);
        keeptrack[i + 1][(i + 2) % 3] = keeptrack[i][(i + 2) % 3];
    }
    fout << keeptrack[100][0] << endl;
    fout << keeptrack[100][1] << endl;
    fout << keeptrack[100][2] << endl;
    return 0;
}