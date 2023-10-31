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
    int wall;
    node(int r, int c, int wall) {
        this->r = r;
        this->c = c;
        this->wall = wall;
    }
}NODE;

class BJ {
    int N, M, K;
    char grid[1000][1000];
    int ***visited;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> N >> M >> K;
    visited = new int **[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new int *[M];
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            visited[i][j] = new int[K+1];
            for (int k = 0; k <= K; k++)
                visited[i][j][k] = INT32_MAX;
        }
    }

    bfs();
    int answer = INT32_MAX;
    for (int i = 0; i <= K; i++)
        answer = min(answer, visited[N-1][M-1][i]);
    cout << (answer == INT32_MAX ? -1 : answer);
}
void BJ::bfs() {
    queue<NODE> Q;
    Q.emplace(0, 0, 0);
    visited[0][0][0] = 1;

    while (!Q.empty()) {
        NODE front = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int r = front.r + dr[i];
            int c = front.c + dc[i];
            if (r < 0 || r >= N || c < 0 || c >= M) continue;
            if (grid[r][c] == '1') {
                if (visited[front.r][front.c][front.wall] % 2 == 1) {
                    if (front.wall + 1 <= K && visited[r][c][front.wall + 1] > visited[front.r][front.c][front.wall] + 1) {
                        visited[r][c][front.wall + 1] = visited[front.r][front.c][front.wall] + 1;
                        Q.emplace(r, c, front.wall + 1);
                    }
                }
                else {
                    if (front.wall + 1 <= K && visited[r][c][front.wall + 1] > visited[front.r][front.c][front.wall] + 2) {
                        visited[r][c][front.wall + 1] = visited[front.r][front.c][front.wall] + 2;
                        Q.emplace(r, c, front.wall + 1);
                    }
                }
            }
            else if (visited[r][c][front.wall] > visited[front.r][front.c][front.wall] + 1){
                visited[r][c][front.wall] = visited[front.r][front.c][front.wall] + 1;
                Q.emplace(r, c, front.wall);
            }
        }
    }
}

signed main() {
    fastIO;

    BJ Q16933;
}