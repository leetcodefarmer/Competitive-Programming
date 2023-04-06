/* USACO 2022 US Open Contest, Bronze Problem 2. Counting Liars http://usaco.org/index.php?page=viewproblem2&cpid=1228 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int location[1000] = {};
int direction[1000] = {};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        int b;
        cin >> a >> b;
        if (a == "G") {
            direction[i] = 1;
        } else {
            direction[i] = -1;
        }
        location[i] = b;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if ((location[i] <= location[j] && direction[j] == -1) || (location[i] >= location[j] && direction[j] == 1)) {
                counter++;
            }
        }
        result = max(result, counter);
    }
    int finalresult = n - result;
    cout << finalresult << endl;
    return 0;
}