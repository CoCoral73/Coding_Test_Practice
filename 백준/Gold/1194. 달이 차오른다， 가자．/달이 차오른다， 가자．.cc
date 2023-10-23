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
    int key;
    int count;
    node(int r, int c, int key, int count) {
        this->r = r;
        this->c = c;
        this->key = key;
        this->count = count;
    }
}NODE;

class BJ {
    int N, M;
    vector<string> maze;
    bool visited[50][50][64];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void bfs(pair<int, int> start);
};

BJ::BJ() {
    cin >> N >> M;
    maze = vector<string>(N);

    pair<int, int> start;
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == '0')
                start = {i, j};
            for (int k = 0; k < 64; k++)
                visited[i][j][k] = false;
        }
    }

    bfs(start);
}
void BJ::bfs(pair<int, int> start) {
    queue<NODE> Q;
    Q.emplace(start.first, start.second, 0, 0);
    visited[start.first][start.second][0] = true;

    while (!Q.empty()) {
        NODE front = Q.front();
        Q.pop();

        if (maze[front.r][front.c] == '1') {
            cout << front.count;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int r = front.r + dr[i];
            int c = front.c + dc[i];
            int key = front.key;
            if (r < 0 || r >= N || c < 0 || c >= M) continue;
            if (maze[r][c] == '#') continue;
            if (visited[r][c][key]) continue;
            if (isupper(maze[r][c])) {
                int need_key = maze[r][c] - 'A';
                if (!(key & (1 << need_key)))
                    continue;
            }
            if (islower(maze[r][c])) {
                key |= (1 << (maze[r][c] - 'a'));
            }
            visited[r][c][key] = true;
            Q.emplace(r, c, key, front.count + 1);
        }
    }
    cout << -1;
    return;
}

signed main() {
    BJ Q1194;
}
