/* USACO 2016 February Contest, Bronze Problem 1. Milk Pails http://www.usaco.org/index.php?page=viewproblem2&cpid=615 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("pails.out");
    ifstream fin ("pails.in");
    int x, y, m;
    fin >> x >> y >> m;
    int runningmax = 0;
    for (int i = 0; i <= floor(m / x); i++) {
        runningmax = max(runningmax, i * x + (int) floor((m - i * x) / y) * y);
    }
    fout << runningmax << endl;
    return 0;
}