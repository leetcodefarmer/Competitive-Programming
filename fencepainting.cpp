/* USACO 2015 December Contest, Bronze Problem 1. Fence Painting http://www.usaco.org/index.php?page=viewproblem2&cpid=567 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    if (a >= d || c >= b) {
        fout << b - a + d - c << endl;
    }
    else {
        fout << max(b, d) - min(a, c) << endl;
    }
    return 0;
}