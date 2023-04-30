/* USACO 2016 December Contest, Bronze Problem 1. Square Pasture http://www.usaco.org/index.php?page=viewproblem2&cpid=663 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("square.out");
    ifstream fin ("square.in");
    int firstx1, firsty1, firstx2, firsty2, secondx1, secondy1, secondx2, secondy2;
    fin >> firstx1 >> firsty1 >> firstx2 >> firsty2 >> secondx1 >> secondy1 >> secondx2 >> secondy2;
    int totalsquarearea = pow(max(max(firstx2, secondx2) - min(firstx1, secondx1), max(firsty2, secondy2) - min(firsty1, secondy1)), 2);
    fout << totalsquarearea << endl;
    return 0;
}