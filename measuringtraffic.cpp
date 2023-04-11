/* USACO 2019 February Contest, Bronze Problem 3. Measuring Traffic http://www.usaco.org/index.php?page=viewproblem2&cpid=917 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

string state[100] = {};
int lowerbound[100] = {};
int upperbound[100] = {};

int main() {
    ofstream fout ("traffic.out");
    ifstream fin ("traffic.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> state[i] >> lowerbound[i] >> upperbound[i];
    }

    int runningintervalstart = 0;
    int runningintervalend = 1000000;
    for (int i = 0; i < N; i++) {
        if (state[i] == "none") {
            runningintervalstart = max(runningintervalstart, lowerbound[i]);
            runningintervalend = min(runningintervalend, upperbound[i]);
        }
        else if (state[i] == "on") {
            runningintervalstart += lowerbound[i];
            runningintervalend += upperbound[i];
        }
        else if (state[i] == "off") {
            runningintervalstart -= upperbound[i];
            runningintervalend -= lowerbound[i];
            runningintervalstart = max(0, runningintervalstart);
        }
    }
    int veryendstart = runningintervalstart;
    int veryendend = runningintervalend;

    runningintervalstart = 0;
    runningintervalend = 1000000;
    for (int i = N - 1; i >= 0; i--) {
        if (state[i] == "none") {
            runningintervalstart = max(runningintervalstart, lowerbound[i]);
            runningintervalend = min(runningintervalend, upperbound[i]);
        }
        else if (state[i] == "on") {
            runningintervalstart -= upperbound[i];
            runningintervalend -= lowerbound[i];
            runningintervalstart = max(0, runningintervalstart);
        }
        else if (state[i] == "off") {
            runningintervalstart += lowerbound[i];
            runningintervalend += upperbound[i];
        }
    }
    int verybeginningstart = runningintervalstart;
    int verybeginningend = runningintervalend;

    fout << verybeginningstart << " " << verybeginningend << endl;
    fout << veryendstart << " " << veryendend << endl;

    return 0;
}