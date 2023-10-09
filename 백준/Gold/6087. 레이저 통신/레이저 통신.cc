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

typedef struct node {
    int r, c;
    int direction;
    int mirror;
    node(int r, int c, int d, int m) {
        this->r = r;
        this->c = c;
        this->direction = d;
        this->mirror = m;
    }
}NODE;

class BJ {
    int W, H;
    vector<string> grid;
    vector<pair<int, int>> Cs;
    int visited[100][100];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> W >> H;
    string line;
    for (int i = 0; i < H; i++) {
        cin >> line;
        grid.emplace_back(line);
        for (int j = 0; j < W; j++) {
            if (line[j] == 'C')
                Cs.emplace_back(i, j);
            visited[i][j] = INT32_MAX;
        }
    }

    bfs();
    cout << visited[Cs[1].first][Cs[1].second];
}
void BJ::bfs() {
    queue<NODE> Q;
    visited[Cs[0].first][Cs[0].second] = 0;
    int r, c, R, C, d, m;

    for (int i = 0; i < 4; i++) {
        r = Cs[0].first + dr[i];
        c = Cs[0].second + dc[i];
        if (r < 0 || r >= H || c < 0 || c >= W) continue;
        if (grid[r][c] == '*') continue;
        Q.emplace(r, c, i, 0);
        visited[r][c] = 0;
    }

    while (!Q.empty()) {
        r = Q.front().r;
        c = Q.front().c;
        d = Q.front().direction;
        m = Q.front().mirror;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            R = r + dr[i];
            C = c + dc[i];
            if (R < 0 || R >= H || C < 0 || C >= W) continue;
            if (grid[R][C] == '*') continue;
            if (visited[R][C] < m + 1) continue;
            if (d % 2 != i % 2) {
                Q.emplace(R, C, i, m + 1);
                visited[R][C] = m + 1;
            }
            else {
                Q.emplace(R, C, i, m);
                visited[R][C] = m;
            }
        }
    }

}

signed main() {
    fastIO;

    BJ Q6087;
}