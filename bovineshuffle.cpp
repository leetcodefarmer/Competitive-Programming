/* USACO 2017 December Contest, Bronze Problem 2. The Bovine Shuffle http://www.usaco.org/index.php?page=viewproblem2&cpid=760 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int shuffler[101] = {};
int order[101] = {};
int originalorder[101] = {};

int main() {
    ofstream fout ("shuffle.out");
    ifstream fin ("shuffle.in");
    int N;
    fin >> N;
    for (int i = 1; i <= N; i++) {
        fin >> shuffler[i];
    }
    for (int i = 1; i <= N; i++) {
        fin >> order[i];
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= N; j++) {
            originalorder[j] = order[shuffler[j]];
        }
        for (int j = 0; j <= N; j++) {
            order[j] = originalorder[j];
        }
    }
    for (int i = 1; i <= N; i++) {
        fout << order[i] << endl;
    }         
    return 0;
}