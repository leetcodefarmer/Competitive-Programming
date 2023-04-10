/* USACO 2017 US Open Contest, Bronze Problem 1. The Lost Cow http://www.usaco.org/index.php?page=viewproblem2&cpid=735 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int line[5000] = {};

int main() {
    ofstream fout ("lostcow.out");
    ifstream fin ("lostcow.in");
    int a, b;
    fin >> a >> b;
    a += 2000;
    b += 2000;
    line[b] = 1;
    int counter = 0;
    int position = a;
    int currentwalk = 1;
    int direction = 1;
    while (line[b] > 0) {
        for (int i = 0; i < currentwalk; i++) {
            counter++;
            position += direction;
            if (line[position] == 1) {
                fout << counter << endl;
                return 0;
            }
        }
        if (currentwalk == 1) {
            currentwalk = 3;
        } else {
            currentwalk *= 2;
        }
        direction *= -1;
    }
    return 0;
}