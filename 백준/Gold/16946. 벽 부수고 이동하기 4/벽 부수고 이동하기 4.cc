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
    int N, M;
    vector<string> grid;
    vector<int> areas;
    int **visited;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void bfs();
    void solution();
};

BJ::BJ() {
    cin >> N >> M;
    grid = vector<string>(N);
    for (string &str : grid)
        cin >> str;

    visited = new int *[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new int[M];
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;
    }

    bfs();
    solution();
}
void BJ::bfs() {
    queue<pair<int, int>> Q;
    int section = 1;
    int r, c, R, C, area;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '1') continue;
            if (visited[i][j] != 0) continue;
            Q.emplace(i, j);
            visited[i][j] = section;
            area = 1;
            while (!Q.empty()) {
                tie(r,c) = Q.front();
                Q.pop();
                for (int a = 0; a < 4; a++) {
                    R = r + dr[a];
                    C = c + dc[a];
                    if (R < 0 || R >= N || C < 0 || C >= M) continue;
                    if (grid[R][C] == '1') continue;
                    if (visited[R][C] != 0) continue;
                    visited[R][C] = section;
                    area++;
                    Q.emplace(R, C);
                }
            }
            areas.emplace_back(area);
            section++;
        }
    }
}
void BJ::solution() {
    set<int> isValid;
    int r, c, sum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '0') {
                cout << 0;
                continue;
            }
            sum = 1;
            isValid.clear();
            for (int a = 0; a < 4; a++) {
                r = i + dr[a];
                c = j + dc[a];
                if (r < 0 || r >= N || c < 0 || c >= M) continue;
                if (grid[r][c] == '1') continue;
                if (isValid.find(visited[r][c]) != isValid.end()) continue;
                sum += areas[visited[r][c]-1];
                isValid.emplace(visited[r][c]);
            }
            cout << sum % 10;
        }
        cout << '\n';
    }
}

signed main() {
    fastIO;

    BJ Q16946;
}