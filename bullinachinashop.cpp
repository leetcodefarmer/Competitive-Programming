/* USACO 2016 US Open Contest, Bronze Problem 2. Bull in a China Shop http://www.usaco.org/index.php?page=viewproblem2&cpid=640 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <numeric>
#include <cstdio>

using namespace std;

bool originalfigure[8][8];
bool pieces[10][8][8];
int boundaries[10][4] = {};

int main() {
    ofstream fout ("bcs.out");
    ifstream fin ("bcs.in");
    int N, K;
    fin >> N >> K;
    for (int i = 0; i < N; i++) {
        string s1;
        fin >> s1;
        for (int j = 0; j < N; j++) {
            originalfigure[j][i] = (s1.substr(j, 1) == "#");
        }
    }
    for (int i = 0; i < K; i++) {
        int minx = N - 1;
        int maxx = 0;
        int miny = N - 1;
        int maxy = 0;
        for (int j = 0; j < N; j++) {
            string s2;
            fin >> s2;
            for (int k = 0; k < N; k++) {
                pieces[i][k][j] = (s2.substr(k, 1) == "#");
                if (pieces[i][k][j]) {
                    minx = min(minx, k);
                    maxx = max(maxx, k);
                    miny = min(miny, j);
                    maxy = max(maxy, j);
                }
            }
        }
        boundaries[i][0] = minx;
        boundaries[i][1] = maxx;
        boundaries[i][2] = miny;
        boundaries[i][3] = maxy;
    }
    for (int a = 0; a < K; a++) {
        for (int b = a + 1; b < K; b++) {
            for (int c = 0; c < N - (boundaries[a][1] - boundaries[a][0]); c++) {
                for (int d = 0; d < N - (boundaries[a][3] - boundaries[a][2]); d++) {
                    for (int e = 0; e < N - (boundaries[b][1] - boundaries[b][0]); e++) {
                        for (int f = 0; f < N - (boundaries[b][3] - boundaries[b][2]); f++) {
                            bool good = true;
                            for (int g = 0; g < N; g++) {
                                for (int h = 0; h < N; h++) {
                                    bool abool = (g >= c) && (g <= c + boundaries[a][1] - boundaries[a][0]) && (h >= d) && (h <= d + boundaries[a][3] - boundaries[a][2]) && pieces[a][g - c + boundaries[a][0]][h - d + boundaries[a][2]];
                                    bool bbool = (g >= e) && (g <= e + boundaries[b][1] - boundaries[b][0]) && (h >= f) && (h <= f + boundaries[b][3] - boundaries[b][2]) && pieces[b][g - e + boundaries[b][0]][h - f + boundaries[b][2]];
                                    if (abool && bbool) {
                                        good = false;
                                        break;
                                    }
                                    if (originalfigure[g][h] != (abool || bbool)) {
                                        good = false;
                                        break;
                                    }
                                }
                                if (!good) {
                                    break;
                                }
                            }
                            if (good) {
                                fout << a + 1 << " " << b + 1 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}