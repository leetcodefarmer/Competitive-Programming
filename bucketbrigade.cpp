/* USACO 2019 US Open Contest, Bronze Problem 1. Bucket Brigade http://usaco.org/index.php?page=viewproblem2&cpid=939 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("buckets.out");
    ifstream fin ("buckets.in");
    int barncoordinatex = 0, barncoordinatey = 0, rockcoordinatex = 0, rockcoordinatey = 0, lakecoordinatex = 0, lakecoordinatey = 0;
    for (int i = 0; i < 10; i++) {
       string s;
       fin >> s;
       for (int j = 0; j < 10; j++) {
            if (s[j] == 'B') {
                barncoordinatex = i;
                barncoordinatey = j;
            }
            if (s[j] == 'R') {
                rockcoordinatex = i;
                rockcoordinatey = j;
            }
            if (s[j] == 'L') {
                lakecoordinatex = i;
                lakecoordinatey = j;
            }
        }
    }
    int shortestdistance;
    if ((lakecoordinatex == rockcoordinatex && rockcoordinatex == barncoordinatex) && ((barncoordinatey < rockcoordinatey && rockcoordinatey < lakecoordinatey) || (lakecoordinatey < rockcoordinatey && rockcoordinatey < barncoordinatey))) {
        shortestdistance = abs(barncoordinatey - lakecoordinatey) + 1;
    } else if ((lakecoordinatey == rockcoordinatey && rockcoordinatey == barncoordinatey) && ((barncoordinatex < rockcoordinatex && rockcoordinatex < lakecoordinatex) || (lakecoordinatex < rockcoordinatex && rockcoordinatex < barncoordinatex))) {
        shortestdistance = abs(barncoordinatex - lakecoordinatex) + 1;
    } else {
        shortestdistance = abs(barncoordinatey - lakecoordinatey) + abs(barncoordinatex - lakecoordinatex) - 1;
    }
    fout << shortestdistance << endl;
    return 0;
}