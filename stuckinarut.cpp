/* USACO 2020 December Contest, Bronze Problem 3. Stuck in a Rut http://www.usaco.org/index.php?page=viewproblem2&cpid=1061 */

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int order[N];
    vector<pair<int, int>> east, north;
    map<int, int> amountofgrasseaten;
    for (int i = 0; i < N; i++) {
        string direction;
        int a, b;
        cin >> direction >> a >> b;
        if (direction == "E") {
            east.push_back(make_pair(a, b));
        } else {
            north.push_back(make_pair(a, b));
        }
        order[i] = a;
        amountofgrasseaten[a] = -1;
    }
    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    for (auto i: east) {
        for (auto j: north) {
            if (amountofgrasseaten[j.first] != -1) {
                continue;
            }
            if (i.second > j.second && i.first < j.first) {
                if (j.first - i.first > i.second - j.second) {
                    amountofgrasseaten[i.first] = j.first - i.first;
                    break;
                }
                else if (j.first - i.first < i.second - j.second) {
                    amountofgrasseaten[j.first] = i.second - j.second;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (amountofgrasseaten[order[i]] == -1) {
            cout << "Infinity" << endl;
        }
        else {
            cout << amountofgrasseaten[order[i]] << endl;
        }
    }
    return 0;
}