/* USACO 2020 December Contest, Bronze Problem 2. Daisy Chains http://www.usaco.org/index.php?page=viewproblem2&cpid=1060 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int flowers[100] = {};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> flowers[i];
    }
    int count = 0;
    int runningtotalforcase = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N - i + 1; j++) {
            for (int k = j; k < j + i; k++) {
                if (k == j) {
                    runningtotalforcase = 0;
                }
                runningtotalforcase += flowers[k];
            }
            for (int k = j; k < j + i; k++) {
                if (i * flowers[k] == runningtotalforcase) {
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}