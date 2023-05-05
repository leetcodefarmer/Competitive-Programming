/* Codeforces Round 587 (Div. 3) Codeforces Round 587 (Div. 3) https://codeforces.com/contest/1216/problem/C */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int firstx1, firsty1, firstx2, firsty2, secondx1, secondy1, secondx2, secondy2, thirdx1, thirdy1, thirdx2, thirdy2;
    cin >> firstx1 >> firsty1 >> firstx2 >> firsty2 >> secondx1 >> secondy1 >> secondx2 >> secondy2 >> thirdx1 >> thirdy1 >> thirdx2 >> thirdy2;
    if (secondx1 <= firstx1 && firstx2 <= secondx2) {
        if (firsty1 >= secondy1) {
            firsty1 = max(firsty1, secondy2);
        }
        if (firsty2 <= secondy2) {
            firsty2 = min(firsty2, secondy1);
        }
    }
    if (secondy1 <= firsty1 && firsty2 <= secondy2) {
        if (firstx1 >= secondx1) {
            firstx1 = max(firstx1, secondx2);
        }
        if (firstx2 <= secondx2) {
            firstx2 = min(firstx2, secondx1);
        }
    }
    if (thirdx1 <= firstx1 && firstx2 <= thirdx2) {
        if (firsty1 >= thirdy1) {
            firsty1 = max(firsty1, thirdy2);
        }
        if (firsty2 <= thirdy2) {
            firsty2 = min(firsty2, thirdy1);
        }
    }
    if (thirdy1 <= firsty1 && firsty2 <= thirdy2) {
        if (firstx1 >= thirdx1) {
            firstx1 = max(firstx1, thirdx2);
        }
        if (firstx2 <= thirdx2) {
            firstx2 = min(firstx2, thirdx1);
        }
    }
    if (firstx1 >= firstx2 && firsty1 >= firsty2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
    return 0;
}