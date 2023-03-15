/* USACO 2020 February Contest, Bronze Problem 1. Triangles http://www.usaco.org/index.php?page=viewproblem2&cpid=1011 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int xcoord[100], ycoord[100];

int main() {
    ofstream fout ("triangles.out");
    ifstream fin ("triangles.in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> xcoord[i] >> ycoord[i];
    }
    int maxarea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (xcoord[i] == xcoord[j] && ycoord[j] == ycoord[k]) {
                    maxarea = max(maxarea, abs((ycoord[i] - ycoord[j]) * (xcoord[j] - xcoord[k])));
                } else if (xcoord[i] == xcoord[j] && ycoord[i] == ycoord[k]) {
                    maxarea = max(maxarea, abs((ycoord[i] - ycoord[j]) * (xcoord[i] - xcoord[k])));
                } else if (xcoord[i] == xcoord[k] && ycoord[i] == ycoord[j]) {
                    maxarea = max(maxarea, abs((ycoord[i] - ycoord[k]) * (xcoord[i] - xcoord[j])));
                } else if (xcoord[i] == xcoord[k] && ycoord[j] == ycoord[k]) {
                    maxarea = max(maxarea, abs((ycoord[i] - ycoord[k]) * (xcoord[j] - xcoord[k])));
                } else if (xcoord[j] == xcoord[k] && ycoord[i] == ycoord[j]) {
                    maxarea = max(maxarea, abs((ycoord[j] - ycoord[k]) * (xcoord[i] - xcoord[j])));
                } else if (xcoord[j] == xcoord[k] && ycoord[i] == ycoord[k]) {
                    maxarea = max(maxarea, abs((ycoord[j] - ycoord[k]) * (xcoord[i] - xcoord[k])));
                }
            }
        }
    }
    fout << maxarea << endl;
    return 0;
}