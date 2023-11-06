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
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int origin[5][5][5];
    int maze[5][5][5];
    int visited[5][5][5];
    int answer = INT32_MAX;
    int df[6] = {0, 0, 0, 0, -1, 1};
    int dr[6] = {-1, 0, 1, 0, 0, 0};
    int dc[6] = {0, 1, 0, -1, 0, 0};
public:
    BJ();
    void dfs(int depth, int floor);
    void bfs();
    void initVisited();
};

BJ::BJ() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++)
                cin >> origin[i][j][k];
        }
    }

    dfs(0, 0);
    cout << (answer == INT32_MAX ? -1 : answer);
}
void BJ::dfs(int depth, int floor) {
    if (depth == 5) {
        bfs();
        answer = min(answer, visited[4][4][4]);
        return ;
    }

    for (int i = 0; i < 5; i++) {
        if (floor & (1 << i)) continue;
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++)
                maze[depth][a][b] = origin[i][a][b];
        }
        if ((depth == 0 && maze[0][0][0]) || (depth == 4 && maze[4][4][4]) || (depth > 0 && depth < 4))
            dfs(depth+1, floor | (1 << i));

        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++)
                maze[depth][a][b] = origin[i][4 - b][a];
        }
        if ((depth == 0 && maze[0][0][0]) || (depth == 4 && maze[4][4][4]) || (depth > 0 && depth < 4))
            dfs(depth+1, floor | (1 << i));

        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++)
                maze[depth][a][b] = origin[i][4 - a][4 - b];
        }
        if ((depth == 0 && maze[0][0][0]) || (depth == 4 && maze[4][4][4]) || (depth > 0 && depth < 4))
            dfs(depth+1, floor | (1 << i));

        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++)
                maze[depth][a][b] = origin[i][b][4 - a];
        }
        if ((depth == 0 && maze[0][0][0]) || (depth == 4 && maze[4][4][4]) || (depth > 0 && depth < 4))
            dfs(depth+1, floor | (1 << i));
    }
}
void BJ::bfs() {
    initVisited();

    queue<tuple<int, int, int>> Q;
    Q.emplace(0, 0, 0);
    visited[0][0][0] = 0;

    int f, r, c;
    while (!Q.empty()) {
        tie(f, r, c) = Q.front();
        Q.pop();
        if (f * r * c == 64)
            break;
        for (int i = 0; i < 6; i++) {
            int F = f + df[i];
            int R = r + dr[i];
            int C = c + dc[i];
            if (F < 0 || F >= 5 || R < 0 || R >= 5 || C < 0 || C >= 5) continue;
            if (maze[F][R][C] == 0) continue;
            if (visited[F][R][C] - 1 <= visited[f][r][c]) continue;
            visited[F][R][C] = visited[f][r][c] + 1;
            Q.emplace(F, R, C);
        }
    }
}
void BJ::initVisited() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                visited[i][j][k] = INT32_MAX;
}

signed main() {
    fastIO;

    BJ Q16985;
}