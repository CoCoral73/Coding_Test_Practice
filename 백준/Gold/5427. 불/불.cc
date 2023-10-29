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
    int r, c;
    int time;
    bool isFire;
    node(int r, int c, int t, bool iF) {
        this->r = r;
        this->c = c;
        this->time = t;
        this->isFire = iF;
    }
}NODE;

class BJ {
    int T;
    int w, h;
    char grid[1000][1000];
    bool visited[1000][1000];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    int bfs(queue<NODE> Q);
};

BJ::BJ() {
    cin >> T;
    while (T--) {
        cin >> w >> h;
        pair<int, int> start;
        queue<NODE> Q;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    Q.emplace(i, j, 0, true);
                    visited[i][j] = true;
                }
                else if (grid[i][j] == '@') {
                    start = {i, j};
                    visited[i][j] = true;
                }
                else
                    visited[i][j] = false;
            }
        }
        Q.emplace(start.first, start.second, 0, false);
        int answer = bfs(Q);
        if (answer == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << answer << '\n';
    }
}
int BJ::bfs(queue<NODE> Q) {
    while (!Q.empty()) {
        NODE front = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int r = front.r + dr[i];
            int c = front.c + dc[i];
            if (r < 0 || r >= h || c < 0 || c >= w) {
                if (!front.isFire) return front.time + 1;
                continue;
            }
            if (grid[r][c] == '#') continue;
            if (visited[r][c]) continue;
            visited[r][c] = true;
            Q.emplace(r, c, front.time + 1, front.isFire);
        }
    }
    return -1;
}

signed main() {
    fastIO;

    BJ Q6593;
}