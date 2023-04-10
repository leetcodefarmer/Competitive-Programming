/* USACO 2015 December Contest, Bronze Problem 2. Speeding Ticket http://www.usaco.org/index.php?page=viewproblem2&cpid=568 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int roadspeed[100] = {};
int bessiespeed[100] = {};

int main() {
    ofstream fout ("speeding.out");
    ifstream fin ("speeding.in");
    int N, M;
    fin >> N >> M;
    int roadcounter = 0;
    int bessiecounter = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        fin >> a >> b;
        for (int j = 0; j < a; j++) {
            roadspeed[roadcounter] = b;
            roadcounter++;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        for (int j = 0; j < a; j++) {
            bessiespeed[bessiecounter] = b;
            bessiecounter++;
        }
    }
    int maxdifference = 0;
    for (int i  = 0; i < 100; i++) {
        if (bessiespeed[i] > roadspeed[i]) {
            maxdifference = max(maxdifference, bessiespeed[i] - roadspeed[i]);
        }
    }
    fout << maxdifference << endl;
    return 0;
}