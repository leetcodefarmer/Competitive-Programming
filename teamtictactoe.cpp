/* USACO 2018 US Open Contest, Bronze Problem 1. Team Tic Tac Toe http://www.usaco.org/index.php?page=viewproblem2&cpid=831 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int singleteams[26] = {};
int pairteams[26][26] = {};
string rows[3] = {};

int main() {
    ofstream fout ("tttt.out");
    ifstream fin ("tttt.in");
    fin >> rows[0];
    fin >> rows[1];
    fin >> rows[2];
    for (int i = 0; i < 3; i++) {
        if (rows[i][0] == rows[i][1] && rows[i][1] == rows[i][2]) {
            singleteams[int(rows[i][0]) - 65] = 1;
        }
        if (rows[0][i] == rows[1][i] && rows[1][i] == rows[2][i]) {
            singleteams[int(rows[0][i]) - 65] = 1;
        }
    }
    if (rows[0][0] == rows[1][1] && rows[1][1] == rows[2][2]) {
        singleteams[int(rows[0][0]) - 65] = 1;
    }
    if (rows[0][2] == rows[1][1] && rows[1][1] == rows[2][0]) {
        singleteams[int(rows[0][2]) - 65] = 1;
    }
    for (int i = 0; i < 3; i++) {
        if (rows[i][0] == rows[i][1] && rows[i][1] != rows[i][2]) {
            pairteams[int(rows[i][0]) - 65][int(rows[i][2]) - 65] = 1;
        }
        if (rows[i][0] == rows[i][2] && rows[i][2] != rows[i][1]) {
            pairteams[int(rows[i][0]) - 65][int(rows[i][1]) - 65] = 1;
        }
        if (rows[i][1] == rows[i][2] && rows[i][2] != rows[i][0]) {
            pairteams[int(rows[i][1]) - 65][int(rows[i][0]) - 65] = 1;
        }
        if (rows[0][i] == rows[1][i] && rows[1][i] != rows[2][i]) {
            pairteams[int(rows[0][i]) - 65][int(rows[2][i]) - 65] = 1;
        }
        if (rows[0][i] == rows[2][i] && rows[2][i] != rows[1][i]) {
            pairteams[int(rows[0][i]) - 65][int(rows[1][i]) - 65] = 1;
        }
        if (rows[1][i] == rows[2][i] && rows[2][i] != rows[0][i]) {
            pairteams[int(rows[1][i]) - 65][int(rows[0][i]) - 65] = 1;
        }
    }
    if (rows[0][0] == rows[1][1] && rows[1][1] != rows[2][2]) {
        pairteams[int(rows[0][0]) - 65][int(rows[2][2]) - 65] = 1;
    }
    if (rows[0][0] == rows[2][2] && rows[2][2] != rows[1][1]) {
        pairteams[int(rows[0][0]) - 65][int(rows[1][1]) - 65] = 1;
    }
    if (rows[1][1] == rows[2][2] && rows[2][2] != rows[0][0]) {
        pairteams[int(rows[1][1]) - 65][int(rows[0][0]) - 65] = 1;
    }
    if (rows[2][0] == rows[1][1] && rows[1][1] != rows[0][2]) {
        pairteams[int(rows[2][0]) - 65][int(rows[0][2]) - 65] = 1;
    }
    if (rows[2][0] == rows[0][2] && rows[0][2] != rows[1][1]) {
        pairteams[int(rows[2][0]) - 65][int(rows[1][1]) - 65] = 1;
    }
    if (rows[1][1] == rows[0][2] && rows[0][2] != rows[2][0]) {
        pairteams[int(rows[1][1]) - 65][int(rows[2][0]) - 65] = 1;
    }
    int singlecounter = 0;
    int paircounter = 0;
    for (int i = 0; i < 26; i++) {
        singlecounter += singleteams[i];
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            paircounter += pairteams[i][j];
            if (pairteams[i][j] == 1) {
                pairteams[j][i] = 0;
            }
        }
    }
    fout << singlecounter << endl;
    fout << paircounter << endl;
    return 0;
}