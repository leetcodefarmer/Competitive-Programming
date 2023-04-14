/* USACO 2017 February Contest, Bronze Problem 3. Why Did the Cow Cross the Road III http://www.usaco.org/index.php?page=viewproblem2&cpid=713 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

using point = pair<int, int>;
vector<point> P;

int main() {
    ofstream fout ("cowqueue.out");
    ifstream fin ("cowqueue.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        fin >> a >> b;
        P.push_back({a, b});
    }
    sort(P.begin(), P.end());
    int counter = P.front().first + P.front().second;
    for (int i = 1; i < P.size(); i++) {
        counter = max(counter + P[i].second, P[i].first + P[i].second);
    }
    fout << counter << endl;
    return 0;
}