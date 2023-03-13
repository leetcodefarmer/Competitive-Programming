/* USACO 2019 February Contest, Bronze Problem 1. Sleepy Cow Herding http://www.usaco.org/index.php?page=viewproblem2&cpid=915 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("herding.out");
    ifstream fin ("herding.in");
    int a, b, c;
    fin >> a >> b >> c;
    int pairdifferences[3] = {abs(a - b), abs(b - c), abs(c - a)};
    std::sort(pairdifferences, pairdifferences + 3);
    int minmoves;
    if ((pairdifferences[0] == 1) && (pairdifferences[1] == 1)) {
        minmoves = 0;
    } else if ((pairdifferences[0] == 2) || (pairdifferences[1] == 2)) {
        minmoves = 1;
    } else {
        minmoves = 2;
    }
    int maxmoves = pairdifferences[1] - 1;
    fout << minmoves << endl << maxmoves << endl;
    return 0;
}