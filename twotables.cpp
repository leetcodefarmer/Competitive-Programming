/* Educational Codeforces Round 112 (Rated for Div. 2) B. Two Tables https://codeforces.com/contest/1555/problem/B */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int totalW, totalH;
        cin >> totalW >> totalH;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;
        int currentmin = 2147483647;
        if (x2 - x1 + w <= totalW) {
            currentmin = min(currentmin, max(0, w - max(x1, totalW - x2)));
        }
        if (y2 - y1 + h <= totalH) {
            currentmin = min(currentmin, max(0, h - max(y1, totalH - y2)));
        }
        if (currentmin == 2147483647) {
            cout << -1 << endl;
        }
        else {
            cout << currentmin << endl;
        }
    }
    return 0;
}