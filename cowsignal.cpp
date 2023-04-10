/* USACO 2016 December Contest, Bronze Problem 3. The Cow-Signal http://www.usaco.org/index.php?page=viewproblem2&cpid=665 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

string strings[10] = {};

int main() {
    ofstream fout ("cowsignal.out");
    ifstream fin ("cowsignal.in");
    int M, N, K;
    fin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        fin >> strings[i];
    }
    for (int i = 0; i < M; i++) {
        string a = "";
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < K; k++) {
                a += strings[i][j];
            }
            if (j == N - 1) {
                for (int l = 0; l < K; l++) {
                    fout << a << endl;
                }
            }
        }
    }
    return 0;
}