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
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct node {
    int floor;
    int r, c;
}NODE;

class BJ {
    int L, R, C;
    string grid[30][30];
    bool visited[30][30][30];
    int dl[6] = {0, 0, 0, 0, -1, 1};
    int dr[6] = {-1, 0, 1, 0, 0, 0};
    int dc[6] = {0, 1, 0, -1, 0, 0};
public:
    BJ();
    int bfs(NODE start);
};

BJ::BJ() {
    while (true) {
        cin >> L >> R >> C;
        if (!(L || R || C)) break;
        NODE start;
        bool flag = false;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> grid[i][j];
                if (!flag) {
                    for (int k = 0; k < C; k++) {
                        if (grid[i][j][k] == 'S') {
                            start = {i, j, k};
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
        int answer = bfs(start);
        if (answer == INT32_MAX)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << answer << " minute(s).\n";
    }
}
int BJ::bfs(NODE start) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++)
                visited[i][j][k] = false;
        }
    }

    queue<pair<NODE, int>> Q;
    Q.emplace(start, 0);
    visited[start.floor][start.r][start.c] = true;

    int answer = INT32_MAX;
    while (!Q.empty()) {
        NODE loc = Q.front().first;
        int time = Q.front().second;
        Q.pop();

        if (grid[loc.floor][loc.r][loc.c] == 'E') {
            answer = min(answer, time);
            break;
        }
        for (int i = 0; i < 6; i++) {
            int f = loc.floor + dl[i];
            int r = loc.r + dr[i];
            int c = loc.c + dc[i];
            if (f < 0 || f >= L || r < 0 || r >= R || c < 0 || c >= C)
                continue;
            if (grid[f][r][c] == '#') continue;
            if (visited[f][r][c]) continue;
            visited[f][r][c] = true;
            Q.push({{f, r, c}, time+1});
        }
    }
    return answer;
}

signed main() {
    fastIO;

    BJ Q6593;
}