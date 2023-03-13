/* USACO 2016 January Contest, Bronze Problem 1. Promotion Counting http://usaco.org/index.php?page=viewproblem2&cpid=591 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("promote.out");
    ifstream fin ("promote.in");
    int abronze, bbronze, asilver, bsilver, agold, bgold, aplatinum, bplatinum;
    fin >> abronze >> bbronze;
    fin >> asilver >> bsilver;
    fin >> agold >> bgold;
    fin >> aplatinum >> bplatinum;
    int goldtoplatinum = bplatinum - aplatinum;
    int silvertogold = goldtoplatinum + bgold - agold;
    int bronzetosilver = silvertogold + bsilver - asilver;
    fout << bronzetosilver << endl << silvertogold << endl << goldtoplatinum << endl;
    return 0;
}