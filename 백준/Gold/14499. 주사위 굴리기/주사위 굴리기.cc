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
    int N, M, x, y, K;
    int grid[20][20];
    int dice[6];
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {1, -1, 0, 0};
public:
    BJ();
    void goEast();
    void goWest();
    void goNorth();
    void goSouth();
};

BJ::BJ() {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    }
    memset(dice, 0, sizeof(int)*6);

    int k;
    while (K--) {
        cin >> k;
        int r = x + dr[k-1];
        int c = y + dc[k-1];
        if (r < 0 || r >= N || c < 0 || c >= M) continue;
        switch (k) {
            case 1:
                goEast(); break;
            case 2:
                goWest(); break;
            case 3:
                goNorth(); break;
            default:
                goSouth();
        }
        cout << dice[0] << '\n';
        if (grid[r][c] == 0)
            grid[r][c] = dice[5];
        else {
            dice[5] = grid[r][c];
            grid[r][c] = 0;
        }
        tie(x, y) = tie(r, c);
    }
}
void BJ::goEast() {
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
}
void BJ::goWest() {
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
}
void BJ::goNorth() {
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
}
void BJ::goSouth() {
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
}

signed main() {
    fastIO;

    BJ Q14499;
}