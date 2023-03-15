/* USACO 2017 February Contest, Bronze Problem 2. Why Did the Cow Cross the Road II http://www.usaco.org/index.php?page=viewproblem2&cpid=712 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("circlecross.out");
    ifstream fin ("circlecross.in");
    string circle;
    fin >> circle;
    int numberintersections = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            string s = "";
            for (int k = 0; k < 52; k++) {
                if (int(circle[k]) - 65 == i || int(circle[k]) - 65 == j) {
                    s += circle[k];
                }
            }
            int i65 = i + 65;
            int j65 = j + 65;
            char iletter = (char)i65;
            char jletter = (char)j65;
            std::string x(1, iletter);
            std::string y(1, jletter);
            string a = x + y + x + y;
            string b = y + x + y + x;
            if (s == a || s == b) {
                numberintersections++;
            }
        }
    }
    fout << numberintersections << endl;
    return 0;
}