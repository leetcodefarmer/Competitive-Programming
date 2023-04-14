/* USACO 2017 January Contest, Bronze Problem 2. Hoof, Paper, Scissors http://www.usaco.org/index.php?page=viewproblem2&cpid=688 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

int whattheyplayed[2][100] = {};

bool whowon(int a, int b, int c) {
    string assigning[4] = {};
    if (c == 1) {
        assigning[1] = "hoof";
        assigning[2] = "paper";
        assigning[3] = "scissors";

    }
    else if (c == 2) {
        assigning[1] = "hoof";
        assigning[2] = "scissors";
        assigning[3] = "paper";
    }
    else if (c == 3) {
        assigning[1] = "paper";
        assigning[2] = "hoof";
        assigning[3] = "scissors";
    }
    else if (c == 4) {
        assigning[1] = "paper";
        assigning[2] = "scissors";
        assigning[3] = "hoof";
    }
    else if (c == 5) {
        assigning[1] = "scissors";
        assigning[2] = "hoof";
        assigning[3] = "paper";
    }
    else if (c == 6) {
        assigning[1] = "scissors";
        assigning[2] = "paper";
        assigning[3] = "hoof";
    }
    if ((assigning[a] == "scissors" && assigning[b] == "paper") || (assigning[a] == "paper" && assigning[b] == "hoof") || (assigning[a] == "hoof" && assigning[b] == "scissors")) {
        return true;
    }
    return false;
}

int main() {
    ofstream fout ("hps.out");
    ifstream fin ("hps.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> whattheyplayed[0][i] >> whattheyplayed[1][i];
    }
    int runningmax = 0;
    for (int i = 1; i <= 6; i++) {
        int counter = 0;
        for (int j = 0; j < N; j++) {
            if (whowon(whattheyplayed[0][j], whattheyplayed[1][j], i)) {
                counter++;
            }
        }
        runningmax = max(runningmax, counter);
    }
    fout << runningmax << endl;
    return 0;
}