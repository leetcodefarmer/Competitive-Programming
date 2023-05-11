/* USACO 2019 January Contest, Bronze Problem 3. Guess the Animal http://www.usaco.org/index.php?page=viewproblem2&cpid=893 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main() {
    ofstream fout ("guess.out");
    ifstream fin ("guess.in");
    int N;
    fin >> N;
    set<string> characteristics[N];
    for (int i = 0; i < N; i++) {
        string name;
        fin >> name;
        int K;
        fin >> K;
        for (int j = 0; j < K; j++) {
            string a;
            fin >> a;
            characteristics[i].insert(a);
        }
    }
    int runningmax = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int counter = 0;
            for (string element: characteristics[i]) {
                if (characteristics[j].count(element)) {
                    counter++;
                }
            }
            runningmax = max(runningmax, counter);
        }
    }
    fout << runningmax + 1 << endl;
    return 0;
}