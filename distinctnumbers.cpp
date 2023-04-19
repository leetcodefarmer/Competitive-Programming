/* Distinct Numbers https://cses.fi/problemset/task/1621/ */

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> integercount = {};
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (integercount[a] == 0) {
            integercount[a]++;
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}