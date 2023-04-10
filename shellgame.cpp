/* USACO 2019 January Contest, Bronze Problem 1. Shell Game http://www.usaco.org/index.php?page=viewproblem2&cpid=891 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int first[100] = {};
int second[100] = {};
int third[100] = {};

int main() {
    ofstream fout ("shell.out");
    ifstream fin ("shell.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> first[i] >> second[i] >> third[i];
    }
    int maxguess = 0;
    for (int i = 1; i <= 3; i++) {
        int counter = 0;
        int currentlyunder = i;
        for (int j = 0; j < N; j++) {
            if (first[j] == currentlyunder) {
                currentlyunder = second[j];
            }
            else if (second[j] == currentlyunder) {
                currentlyunder = first[j];
            }
            if (currentlyunder == third[j]) {
                counter++;
            }
        }
        maxguess = max(maxguess, counter);
    }
    fout << maxguess << endl;
    return 0;
}