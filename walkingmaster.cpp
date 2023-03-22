/* Codeforces Round 858 (Div. 2) A. Walking Master https://codeforces.com/contest/1806/problem/A */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d < b || d < b + c - a) {
            int x = -1;
            cout << x << endl;
        } else {
            int y = a - 2 * b - c + 2 * d;
            cout << y << endl;
        }
    }
    return 0;
}