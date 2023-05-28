/* USACO 2016 February Contest, Silver Problem 2. Load Balancing http://www.usaco.org/index.php?page=viewproblem2&cpid=619 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("balancing.out");
    ifstream fin ("balancing.in");
    int N;
    fin >> N;
    pair<int, int> coords[N];
    for (int i = 0; i < N; i++) {
        fin >> coords[i].first >> coords[i].second;
    }
    sort(coords, coords + N);
    int runningmin = 1001;
    for (int i = 0; i < N; i++) {
        int upperright = 0;
        int upperleft = 0;
        int lowerleft = 0;
        int lowerright = 0;
        for (int j = 0; j < N; j++) {
            if (coords[j].second < coords[i].second) {
                lowerright++;
            }
            else {
                upperright++;
            }
        }
        runningmin = min(runningmin, max(lowerright, upperright));
        for (int j = 0; j < N; j++) {
            if (coords[j].second < coords[i].second) {
                lowerleft++;
                lowerright--;
            }
            else {
                upperleft++;
                upperright--;
            }
            runningmin = min(runningmin, max(upperright, max(upperleft, max(lowerleft, lowerright))));
        }
    }
    fout << runningmin << endl;
    return 0;
}