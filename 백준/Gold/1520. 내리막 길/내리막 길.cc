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
    int M, N;
    int grid[500][500];
    int visit[500][500];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int answer = 0;
public:
    BJ();
    void dfs(int r, int c);
};

BJ::BJ() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visit[i][j] = -1;
        }
    }

    dfs(0, 0);
    cout << answer;
}
void BJ::dfs(long long r, long long c) {
    visit[r][c] = 0;
    if (r == M-1 && c == N-1) {
        answer++;
        visit[r][c]++;
        return ;
    }

    int R, C;
    for (int i = 0; i < 4; i++) {
        R = r + dr[i];
        C = c + dc[i];
        if (R < 0 || R >= M || C < 0 || C >= N)
            continue;
        if (grid[R][C] >= grid[r][c]) {
            continue;
        }
        if (visit[R][C] != -1) {
            answer += visit[R][C];
            visit[r][c] += visit[R][C];
            continue;
        }
        dfs(R, C);
        visit[r][c] += visit[R][C];
    }
}

signed main() {
    fastIO;
    BJ Q1520;
}