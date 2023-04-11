/* USACO 2016 February Contest, Bronze Problem 2. Circular Barn http://www.usaco.org/index.php?page=viewproblem2&cpid=616 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int rooms[1000] = {};

int main() {
    ofstream fout ("cbarn.out");
    ifstream fin ("cbarn.in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> rooms[i];
    }
    int runningminimum = 1000000000;
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = i + 1; j < n + i; j++) {
            counter += (j - i) * rooms[j % n];
        }
        runningminimum = min(runningminimum, counter);
    }
    fout << runningminimum << endl;
    return 0;
}