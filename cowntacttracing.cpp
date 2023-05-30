/* USACO 2020 US Open Contest, Bronze Problem 3. Cowntact Tracing http://www.usaco.org/index.php?page=viewproblem2&cpid=1037 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <numeric>

using namespace std;

int cowx[251] = {};
int cowy[251] = {};
int patientzero[101] = {};

int main() {
    ofstream fout ("tracing.out");
    ifstream fin ("tracing.in");
    int N, T;
    fin >> N >> T;
    string s;
    fin >> s;
    int maxtime = 0;
    for (int i = 0; i < T; i++) {
        int t, x, y;
        fin >> t >> x >> y;
        cowx[t] = x;
        cowy[t] = y;
        maxtime = max(maxtime, t);
    }
    int minkvalue = 2147483647;
    int maxkvalue = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            bool infectedcow[101] = {false};
            int runningT[101] = {};
            infectedcow[i] = true;
            runningT[i] = j;
            for (int k = 1; k <= maxtime; k++) {
                if (cowx[k] != 0) {
                    if (runningT[cowx[k]] > 0 && infectedcow[cowy[k]] == false) {
                        infectedcow[cowy[k]] = true;
                        runningT[cowy[k]] = j;
                        runningT[cowx[k]]--;
                    }
                    else if (runningT[cowy[k]] > 0 && infectedcow[cowx[k]] == false) {
                        infectedcow[cowx[k]] = true;
                        runningT[cowx[k]] = j;
                        runningT[cowy[k]]--;
                    }
                    else if (infectedcow[cowx[k]] == true && infectedcow[cowy[k]] == true) {
                        runningT[cowx[k]]--;
                        runningT[cowy[k]]--;
                    }
                }
            }
            bool doesitwork = true;
            for (int k = 1; k <= N; k++) {
                if (stoi(s.substr(k - 1, 1)) != int(infectedcow[k])) {
                    doesitwork = false;
                    break;
                }
            }
            if (doesitwork) {
                patientzero[i] = 1;
                minkvalue = min(minkvalue, j);
                maxkvalue = max(maxkvalue, j);
            }
        }
    }
    if (maxkvalue == T) {
        fout << accumulate(patientzero, patientzero + 101, 0) << " " << minkvalue << " " << "Infinity";
    }
    else {
        fout << accumulate(patientzero, patientzero + 101, 0) << " " << minkvalue << " " << maxkvalue;
    }
    return 0;
}