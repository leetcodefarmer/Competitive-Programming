/* USACO 2022 February Contest, Bronze Problem 1. Sleeping in Class http://www.usaco.org/index.php?page=viewproblem2&cpid=1203 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int logs[100000];

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int testcasesum = 0;
        for (int j = 0; j < n; j++) {
            cin >> logs[j];
            testcasesum += logs[j];
        }
        for (int k = n; k >= 1; k--) {
            if (testcasesum % k == 0) {
                int finalcombinedsize = testcasesum / k;
                int counter = 0;
                bool onoffswitch = true;
                for (int l = 0; l < n; l++) {
                    counter += logs[l];
                    if (counter > finalcombinedsize) {
                        onoffswitch = false;
                        break;
                    }
                    if (counter == finalcombinedsize) {
                        counter= 0;
                    }
                }
                if (onoffswitch) {
                    cout << n - k << endl;
                    break;
                }
            }
        }
    }
    return 0;
}