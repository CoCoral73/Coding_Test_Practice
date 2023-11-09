#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <memory.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, L;
    int grid[100][100];
    int stair[100][100];
    int vertical = 0, horizontal = 0;
public:
    BJ();
    void solution();
};

BJ::BJ() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            stair[i][j] = 0;
        }
    }

    solution();
    cout << vertical + horizontal;
}
void BJ::solution() {
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < N-1; j++) {
            if (abs(grid[i][j] - grid[i][j+1]) >= 2) { flag = false; break; }
            if (grid[i][j] == grid[i][j+1]) continue;
            if (grid[i][j] < grid[i][j+1]) {
                for (int k = 0; k < L; k++) {
                    if (j - k < 0) { flag = false; break; }
                    if (grid[i][j] != grid[i][j-k]) { flag = false; break; }
                    if (stair[i][j-k] == 1) { flag = false; break; }
                }
                if (flag) {
                    for (int k = 0; k < L; k++)
                        stair[i][j-k] = 1;
                }
            }
            else {
                for (int k = 0; k < L; k++) {
                    if (j + k >= N) { flag = false; break; }
                    if (grid[i][j+1] != grid[i][j+1+k]) { flag = false; break; }
                    if (stair[i][j+1+k] == 1) { flag = false; break; }
                }
                if (flag) {
                    for (int k = 0; k < L; k++)
                        stair[i][j+1+k] = 1;
                }
            }
        }
        if (flag) vertical++;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            stair[i][j] = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < N-1; j++) {
            if (abs(grid[j][i] - grid[j+1][i]) >= 2) { flag = false; break; }
            if (grid[j][i] == grid[j+1][i]) continue;
            if (grid[j][i] < grid[j+1][i]) {
                for (int k = 0; k < L; k++) {
                    if (j - k < 0) { flag = false; break; }
                    if (grid[j][i] != grid[j-k][i]) { flag = false; break; }
                    if (stair[j-k][i] == 1) { flag = false; break; }
                }
                if (flag) {
                    for (int k = 0; k < L; k++)
                        stair[j-k][i] = 1;
                }
            }
            else {
                for (int k = 0; k < L; k++) {
                    if (j + k >= N) { flag = false; break; }
                    if (grid[j+1][i] != grid[j+1+k][i]) { flag = false; break; }
                    if (stair[j+1+k][i] == 1) { flag = false; break; }
                }
                if (flag) {
                    for (int k = 0; k < L; k++)
                        stair[j+1+k][i] = 1;
                }
            }
        }
        if (flag) horizontal++;
    }
}

signed main() {
    fastIO;

    BJ Q14890;
}