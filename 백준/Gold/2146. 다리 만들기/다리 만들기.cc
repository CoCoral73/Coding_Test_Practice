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

class BJ {
    int N;
    int grid[100][100];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool visited[100][100];
    int answer = INT32_MAX;
public:
    BJ();
    void bfs_section(int r, int c, int n);
    void bfs_bridge(int r, int c);
};

BJ::BJ() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int section = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || grid[i][j] == 0) continue;
            bfs_section(i, j, section);
            section++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) continue;
            bool flag = false;
            for (int k = 0; k < 4; k++) {
                int R = i + dr[k];
                int C = j + dc[k];
                if (R < 0 || R >= N || C < 0 || C >= N) continue;
                if (grid[R][C] == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                for (int a = 0; a < N; a++) {
                    for (int b = 0; b < N; b++)
                        visited[a][b] = false;
                }
                bfs_bridge(i, j);
            }
        }
    }

    cout << answer;
}
void BJ::bfs_section(int r, int c, int n) {
    queue<pair<int, int>> Q;
    Q.emplace(r, c);
    visited[r][c] = true;
    grid[r][c] = n;

    while (!Q.empty()) {
        tie(r, c) = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int R = r + dr[i];
            int C = c + dc[i];
            if (R < 0 || R >= N || C < 0 || C >= N) continue;
            if (grid[R][C] == 0) continue;
            if (visited[R][C]) continue;
            visited[R][C] = true;
            grid[R][C] = n;
            Q.emplace(R, C);
        }
    }
}

typedef struct node {
    int r, c;
    int count;
    node(int r, int c, int count) {
        this->r = r;
        this->c = c;
        this->count = count;
    }
}NODE;
void BJ::bfs_bridge(int r, int c) {
    queue<NODE> Q;
    Q.emplace(r, c, 0);

    while (!Q.empty()) {
        NODE front = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int R = front.r + dr[i];
            int C = front.c + dc[i];
            if (R < 0 || R >= N || C < 0 || C >= N) continue;
            if (grid[R][C] == 0) {
                if (visited[R][C]) continue;
                visited[R][C] = true;
                Q.emplace(R, C, front.count + 1);
            }
            else if (grid[R][C] != grid[r][c]) {
                answer = min(answer, front.count);
                break;
            }
        }
    }
}

signed main() {
    fastIO;

    BJ Q2961;
}