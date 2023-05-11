/* USACO Guide Problem Submission A. Maximum Distance https://codeforces.com/gym/102951/problem/A */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int xcoord[5000] = {};
int ycoord[5000] = {};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> xcoord[i];
    }
    for (int i = 0; i < N; i ++) {
        cin >> ycoord[i];
    }
    int runningmax = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            runningmax = max(runningmax, (xcoord[i] - xcoord[j]) * (xcoord[i] - xcoord[j]) + (ycoord[i] - ycoord[j]) * (ycoord[i] - ycoord[j]));
        }
    }
    cout << runningmax << endl;
    return 0;
}