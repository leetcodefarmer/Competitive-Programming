/* USACO 2020 January Contest, Bronze Problem 2. Photoshoot http://www.usaco.org/index.php?page=viewproblem2&cpid=988 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int barray[999];
int dowehaveit[1000] = {};
int inorder[1000] = {};

int main() {
    ofstream fout ("photo.out");
    ifstream fin ("photo.in");
    int n;
    fin >> n;
    for (int i = 0; i < n - 1; i++) {
        fin >> barray[i];
    }
    for (int i = 1; i <= n; i++) {
        bool goahead = true;
        std::fill(dowehaveit, dowehaveit + 1000, 0);
        std::fill(inorder, inorder + 1000, 0);
        int previous = i;
        dowehaveit[i]++;
        inorder[0] = i;
        for (int j = 0; j < n - 1; j++) {
            int x = barray[j] - previous;
            if (dowehaveit[x] == 1 || x <= 0 || x > n) {
                goahead = false;
                break;
            }
            dowehaveit[x]++;
            inorder[j+1] = x;
            previous = x;
        }
        if (goahead == true) {
            for (int k = 0; k < n; k++) {
                fout << inorder[k];
                if (k < n - 1) {
                    fout << ' ';
                }
            }
            fout << endl;
            return 0;
        }
    }
}