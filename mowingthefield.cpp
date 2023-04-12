/* USACO 2016 January Contest, Bronze Problem 3. Mowing the Field http://www.usaco.org/index.php?page=viewproblem2&cpid=593 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int coordinatetimevisited[2002][2002] = {};
string direction[100] = {};
int stepsindirection[100] = {};

int main() {
    ofstream fout ("mowing.out");
    ifstream fin ("mowing.in");
    int N;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> direction[i] >> stepsindirection[i];
    }
    int counter = 1;
    int currentx = 1001;
    int currenty = 1001;
    coordinatetimevisited[1001][1001] = 1;
    int mindifference = 1002;
    for (int i = 0; i < N; i++) {
        if (direction[i] == "N") {
            for (int j = 0; j < stepsindirection[i]; j++) {
                currenty++;
                counter++;
                if (coordinatetimevisited[currentx][currenty] > 0) {
                    mindifference = min(mindifference, counter - coordinatetimevisited[currentx][currenty]);
                }
                coordinatetimevisited[currentx][currenty] = counter;
            }
        }
        else if (direction[i] == "S") {
            for (int j = 0; j < stepsindirection[i]; j++) {
                currenty--;
                counter++;
                if (coordinatetimevisited[currentx][currenty] > 0) {
                    mindifference = min(mindifference, counter - coordinatetimevisited[currentx][currenty]);
                }
                coordinatetimevisited[currentx][currenty] = counter;
            }

        }
        else if (direction[i] == "W") {
            for (int j = 0; j < stepsindirection[i]; j++) {
                currentx--;
                counter++;
                if (coordinatetimevisited[currentx][currenty] > 0) {
                    mindifference = min(mindifference, counter - coordinatetimevisited[currentx][currenty]);
                }
                coordinatetimevisited[currentx][currenty] = counter;
            }
        }
        else if (direction[i] == "E") {
            for (int j = 0; j < stepsindirection[i]; j++) {
                currentx++;
                counter++;
                if (coordinatetimevisited[currentx][currenty] > 0) {
                    mindifference = min(mindifference, counter - coordinatetimevisited[currentx][currenty]);
                }
                coordinatetimevisited[currentx][currenty] = counter;
            }
        }
    }
    if (mindifference == 1002) {
        fout << -1 << endl;
    }
    else {
        fout << mindifference << endl;
    }
    return 0;
}