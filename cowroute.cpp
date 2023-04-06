/* USACO 2015 January Contest, Bronze Problem 1. Cow Routing http://www.usaco.org/index.php?page=viewproblem2&cpid=507 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("cowroute.out");
    ifstream fin ("cowroute.in");
    int A, B, N;
    fin >> A >> B >> N;
    int mincost = 1001;
    for (int i = 0; i < N; i++) {
        int c, d;
        fin >> c >> d;
        bool acounter = false;
        for (int j = 0; j < d; j++) {
            int e;
            fin >> e;
            if (e == A) {
                acounter = true;
            }
            if (e == B && acounter) {
                mincost = min(c, mincost);
            }
        }
    }
    if (mincost == 1001) {
        fout << -1 << endl;
    } else {
        fout << mincost << endl;
    }
    return 0;
}