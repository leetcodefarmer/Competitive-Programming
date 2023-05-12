/* USACO 2016 February Contest, Bronze Problem 3. Load Balancing http://www.usaco.org/index.php?page=viewproblem2&cpid=617 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int xcoord[101], ycoord[101];

int main() {
    ofstream fout ("balancing.out");
    ifstream fin ("balancing.in");
    int N, B;
    fin >> N >> B;
    for (int i = 0; i < N; i++) {
        fin >> xcoord[i] >> ycoord[i];
    }
    int runningmin = 101;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int pointx = xcoord[i] + 1;
            int pointy = ycoord[j] + 1;
            int upperright = 0;
            int upperleft = 0;
            int lowerleft = 0;
            int lowerright = 0;
            for (int k = 0; k < N; k++) {
                if (xcoord[k] > pointx && ycoord[k] > pointy) {
                    upperright++;
                }
                else if (xcoord[k] < pointx && ycoord[k] > pointy) {
                    upperleft++;
                }
                else if (xcoord[k] < pointx && ycoord[k] < pointy) {
                    lowerleft++;    
                }
                else {
                    lowerright++;
                }
            }
            runningmin = min(runningmin, max(upperright, max(upperleft, max(lowerleft, lowerright))));
        }
    }
    fout << runningmin << endl;
    return 0;
}