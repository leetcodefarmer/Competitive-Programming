/* USACO 2017 December Contest, Bronze Problem 1. Blocked Billboard http://www.usaco.org/index.php?page=viewproblem2&cpid=759 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("billboard.out");
    ifstream fin ("billboard.in");
    int firstx1, firsty1, firstx2, firsty2, secondx1, secondy1, secondx2, secondy2, truckx1, trucky1, truckx2, trucky2;
    fin >> firstx1 >> firsty1 >> firstx2 >> firsty2 >> secondx1 >> secondy1 >> secondx2 >> secondy2 >> truckx1 >> trucky1 >> truckx2 >> trucky2;
    int totalbillboardarea = (firstx2 - firstx1) * (firsty2 - firsty1) + (secondx2 - secondx1) * (secondy2 - secondy1);
    int totaloverlaparea = max(0, min(firstx2, truckx2) - max(firstx1, truckx1)) * max(0, min(firsty2, trucky2) - max(firsty1, trucky1)) + max(0, min(secondx2, truckx2) - max(secondx1, truckx1)) * max(0, min(secondy2, trucky2) - max(secondy1, trucky1));
    fout << totalbillboardarea - totaloverlaparea << endl;
    return 0;
}