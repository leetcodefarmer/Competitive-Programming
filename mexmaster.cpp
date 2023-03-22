/* Codeforces Round 858 (Div. 2) B. Mex Master https://codeforces.com/contest/1806/problem/B */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int counter[2] = {};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        std::fill(counter, counter + 2, 0);
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int p;
            cin >> p;
            if (p == 0) {
                counter[0]++;
            } else if (p > 1) {
                counter[1]++;
            }
        }
        if (counter[0] <= (m + 1) / 2) {
            cout << 0 << endl;
        } else if (counter[1] > 0 || counter[0] == m) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}