/* USACO 2019 December Contest, Bronze Problem 2. Where Am I? http://usaco.org/index.php?page=viewproblem2&cpid=964 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    int n;
    fin >> n;
    string s;
    fin >> s;
    bool onoffswitch = true;
    for (int i = 1; i <= n - 1; i++) {
        onoffswitch = true;
        for (int j = 0; j < n - i; j++) {
            for (int k = j + 1; k < n - i + 1; k++) {
                if (s.substr(j, i) == s.substr(k, i)) {
                    onoffswitch = false;
                    break;
                }
            }
            if (onoffswitch == false) {
                break;
            }
        }
        if (onoffswitch == true) {
            fout << i << endl;
            return 0;
        }
    }
    fout << n << endl;
    return 0;
}