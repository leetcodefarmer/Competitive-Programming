/* USACO 2018 February Contest, Bronze Problem 1. Teleportation http://www.usaco.org/index.php?page=viewproblem2&cpid=807 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("teleport.out");
    ifstream fin ("teleport.in");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    int bruteforce = abs(a - b);
    int teleporterlength = abs(min(a, b) - min(c, d)) + abs(max(a, b) - max(c, d));
    int actualminimum = min(bruteforce, teleporterlength);
    fout << actualminimum << endl;
    return 0;
}