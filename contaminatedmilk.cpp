/* USACO 2015 December Contest, Bronze Problem 3. Contaminated Milk http://www.usaco.org/index.php?page=viewproblem2&cpid=569 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;

int sicktimes[51] = {};
int sicktimes1[51] = {};

int main() {
    ofstream fout ("badmilk.out");
    ifstream fin ("badmilk.in");
    int N, M, D, S;
    fin >> N >> M >> D >> S;
    vector<tuple<int, int, int>> milktypepersontime;
    for (int i = 0; i < D; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        milktypepersontime.push_back({b, a, c});
    }
    sort(milktypepersontime.begin(), milktypepersontime.end());
    std::fill_n(sicktimes, 51, 101);
    for (int i = 0; i < S; i++) {
        int a, b;
        fin >> a >> b;
        sicktimes[a] = b;
    }
    std::fill_n(sicktimes1, 51, 101);
    int currentmilktype = 1;
    int mindoses = 0;
    int counter = 0;
    for (int i = 0; i < milktypepersontime.size(); i++) {
        if (currentmilktype != get<0>(milktypepersontime[i])) {
            currentmilktype = get<0>(milktypepersontime[i]);
            std::fill_n(sicktimes1, 51, 101);
        }
        sicktimes1[get<1>(milktypepersontime[i])] = min(sicktimes1[get<1>(milktypepersontime[i])], get<2>(milktypepersontime[i]));
        if (i == milktypepersontime.size() - 1 || currentmilktype != get<0>(milktypepersontime[i + 1])) {
            for (int j = 1; j <= N; j++) {
                if (j == 1) {
                    counter = 0;
                }
                if (sicktimes1[j] > sicktimes[j]) {
                    break;
                }
                if (sicktimes1[j] < sicktimes[j]) {
                    counter++;
                }
                if (j == N) {
                    mindoses = max(mindoses, counter);
                }
            }
        }
    }
    fout << mindoses << endl;
    return 0;
}