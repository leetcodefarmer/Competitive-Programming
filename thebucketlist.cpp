/* USACO 2018 December Contest, Bronze Problem 2. The Bucket List http://www.usaco.org/index.php?page=viewproblem2&cpid=856 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

using point = pair<int, int>;
vector<point> P;

int main() {
    ofstream fout ("blist.out");
    ifstream fin ("blist.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        P.push_back({a, c});
        P.push_back({b, -c});
    }
    sort(P.begin(), P.end());
    int maxbuckets = 0;
    int counter = 0;
    for (int i = 0; i < P.size(); i++) {
        counter += P[i].second;
        maxbuckets = max(maxbuckets, counter);
    }
    fout << maxbuckets << endl;
    return 0;
}