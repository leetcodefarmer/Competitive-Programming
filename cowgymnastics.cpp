/* USACO 2019 December Contest, Bronze Problem 1. Cow Gymnastics http://www.usaco.org/index.php?page=viewproblem2&cpid=963 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int gymarray[10][20], pairarray[20][20];

int main() {
    ofstream fout ("gymnastics.out");
    ifstream fin ("gymnastics.in");
    int k, n;
    fin >> k >> n;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
           fin >> gymarray[i][j];
           gymarray[i][j]--; 
        }
    }
    int counter = 0;
    for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = j + 1; l < n; l++) {
                    int a = gymarray[i][j];
                    int b = gymarray[i][l];
                    pairarray[a][b]++;
                }
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pairarray[i][j] == k) {
                    counter++;
            }
        }
    }
    fout << counter << endl;
    return 0;
}