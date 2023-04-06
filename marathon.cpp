/* USACO 2014 December Contest, Bronze Problem 1. Marathon http://www.usaco.org/index.php?page=viewproblem2&cpid=487 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int a[100000] = {};
int b[100000] = {};

int main() {
    ofstream fout ("marathon.out");
    ifstream fin ("marathon.in");
    int n;
    fin >> n;
    int x = 0;
    int y = 0;
    fin >> a[0] >> b[0];
    for (int i = 1; i < n; i++) {
        fin >> a[i] >> b[i];
        x += abs(a[i] - a[i - 1]);
        y += abs(b[i] - b[i - 1]);
    }
    int minimum = x + y;
    for (int i = 1; i < n - 1; i++) {
        minimum = min(x + y - abs(a[i] - a[i - 1]) - abs(b[i] - b[i - 1]) - abs(a[i + 1] - a[i]) - abs(b[i + 1] - b[i]) + abs(a[i + 1] - a[i - 1]) + abs(b[i + 1] - b[i - 1]), minimum);
        }
    fout << minimum << endl;
    return 0;
}