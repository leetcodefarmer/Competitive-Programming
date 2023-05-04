/* USACO 2018 January Contest, Bronze Problem 1. Blocked Billboard II http://www.usaco.org/index.php?page=viewproblem2&cpid=783 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("billboard.out");
    ifstream fin ("billboard.in");
    int firstx1, firsty1, firstx2, firsty2, secondx1, secondy1, secondx2, secondy2;
    fin >> firstx1 >> firsty1 >> firstx2 >> firsty2 >> secondx1 >> secondy1 >> secondx2 >> secondy2;
    int totalarea = (firstx2 - firstx1) * (firsty2 - firsty1);
    int cornerscovered = 0;
    if (secondx1 <= firstx1 && firstx1 <= secondx2 && secondy1 <= firsty1 && firsty1 <= secondy2) {
        cornerscovered++;
    }
    if (secondx1 <= firstx1 && firstx1 <= secondx2 && secondy1 <= firsty2 && firsty2 <= secondy2) {
        cornerscovered++;
    }
    if (secondx1 <= firstx2 && firstx2 <= secondx2 && secondy1 <= firsty1 && firsty1 <= secondy2) {
        cornerscovered++;
    }
    if (secondx1 <= firstx2 && firstx2 <= secondx2 && secondy1 <= firsty2 && firsty2 <= secondy2) {
        cornerscovered++;
    }
    if (cornerscovered == 4) {
        fout << 0 << endl;
    }
    else if (cornerscovered == 2) {
        fout << totalarea - (min(firstx2, secondx2) - max(firstx1, secondx1)) * (min(firsty2, secondy2) - max(firsty1, secondy1)) << endl;
    }
    else {
        fout << totalarea << endl;
    }
    return 0;
}