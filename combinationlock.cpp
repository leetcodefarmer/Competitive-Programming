/* USACO 2013 November Contest, Bronze Problem 1. Combination Lock http://usaco.org/index.php?page=viewproblem2&cpid=340 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int n, firstlockone, firstlocktwo, firstlockthree, secondlockone, secondlocktwo, secondlockthree;
    fin >> n;
    fin >> firstlockone >> firstlocktwo >> firstlockthree;
    fin >> secondlockone >> secondlocktwo >> secondlockthree;
    int distinctconfigs;
    if (n <= 5) {
        distinctconfigs = n * n * n;
    } else if (n <= 9) {
        distinctconfigs = 250 - max(5 - min(abs(firstlockone - secondlockone), n - abs(firstlockone - secondlockone)), 10 - n) * max(5 - min(abs(firstlocktwo - secondlocktwo), n - abs(firstlocktwo - secondlocktwo)), 10 - n) * max(5 - min(abs(firstlockthree - secondlockthree), n - abs(firstlockthree - secondlockthree)), 10 - n);
    } else {
        distinctconfigs = 250 - max(5 - min(abs(firstlockone - secondlockone), n - abs(firstlockone - secondlockone)), 0) * max(5 - min(abs(firstlocktwo - secondlocktwo), n - abs(firstlocktwo - secondlocktwo)), 0) * max(5 - min(abs(firstlockthree - secondlockthree), n - abs(firstlockthree - secondlockthree)), 0);
    }
    fout << distinctconfigs << endl;
    return 0;
}