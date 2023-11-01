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
    int N, M;
    bool light[100][100];
    bool visited1[100][100];
    bool visited2[100][100];
    vector<pair<int, int>> Switch[100][100];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int answer;
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            light[i][j] = false;
            visited1[i][j] = false;
        }
    }

    int x, y, a, b;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        Switch[x-1][y-1].emplace_back(a-1, b-1);
    }

    bfs();
    cout << answer;
}
void BJ::bfs() {
    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    visited1[0][0] = true;
    light[0][0] = true;
    answer = 1;

    int r, c;
    while (!Q.empty()) {
        tie(r, c) = Q.front();
        Q.pop();

        for (pair p : Switch[r][c]) {
            int R = p.first;
            int C = p.second;
            if (light[R][C]) continue;
            light[R][C] = true;
            answer++;
        }

        queue<pair<int, int>> BQ;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visited2[i][j] = false;
        BQ.emplace(0, 0);
        visited2[0][0] = true;
        while (!BQ.empty()) {
            tie(r, c) = BQ.front();
            BQ.pop();

            for (int i = 0; i < 4; i++) {
                int R = r + dr[i];
                int C = c + dc[i];
                if (R < 0 || R >= N || C < 0 || C >= N) continue;
                if (!light[R][C] || visited2[R][C]) continue;
                visited2[R][C] = true;
                BQ.emplace(R, C);
                if (Switch[R][C].size() > 0 && !visited1[R][C]) {
                    visited1[R][C] = true;
                    Q.emplace(R, C);
                }
            }
        }
    }
}

signed main() {
    fastIO;

    BJ Q11967;
}