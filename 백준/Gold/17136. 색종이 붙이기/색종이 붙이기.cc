#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int grid[10][10];
    bool visit[10][10];
    int paper[5] = {5,5,5,5,5};
    int total = 0;
    int answer = INT32_MAX;
public:
    BJ();
    void solution(int cover, int count);
};

BJ::BJ() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            visit[i][j] = false;
            if (grid[i][j] == 1) total++;
        }
    }
    solution(0, 0);
    cout << (answer == INT32_MAX ? -1 : answer);
}
void BJ::solution(int cover, int count) {
    if (total == cover) {
        answer = min(answer, count);
        return;
    }
    int r = 0, c = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1 && !visit[i][j]) {
                r = i, c = j;
                goto STEP1;
            }
        }
    }
    STEP1:
    for (int size = 5; size >= 1; size--) {
        if (r + size - 1 >= 10 || c + size - 1 >= 10)
            continue;
        if (paper[size-1] == 0)
            continue;
        bool flag = true;
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (grid[i][j] == 0 || visit[i][j]) {
                    flag = false;
                    goto STEP2;
                }
            }
        }
    STEP2:
        if (!flag) {
            continue;
        }
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                visit[i][j] = true;
            }
        }
        paper[size-1]--;
        solution(cover+size*size, count+1);
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++)
                visit[i][j] = false;
        }
        paper[size-1]++;
    }
}

signed main() {
    fastIO;
    BJ Q17136;
}