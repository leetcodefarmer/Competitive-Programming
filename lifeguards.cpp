/* USACO 2018 January Contest, Bronze Problem 2. Lifeguards http://www.usaco.org/index.php?page=viewproblem2&cpid=784 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int totalinterval[1000] = {};
int intervalstarts[100] = {};
int intervalends[100] = {};

int main() {
    ofstream fout ("lifeguards.out");
    ifstream fin ("lifeguards.in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> intervalstarts[i] >> intervalends[i];
        for (int j = intervalstarts[i]; j < intervalends[i]; j++) {
            totalinterval[j]++;
        }
    }
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = intervalstarts[i]; j < intervalends[i]; j++) {
            totalinterval[j]--;
        }
        for (int k = 0; k < 1000; k++) {
            if (totalinterval[k] > 0) {
                counter++;
            }
        }
        maximum = max(maximum, counter);
        for (int j = intervalstarts[i]; j < intervalends[i]; j++) {
            totalinterval[j]++;
        }
    }
    fout << maximum << endl;
    return 0;
}