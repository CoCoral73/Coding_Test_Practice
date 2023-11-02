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
    int N, M, P;
    vector<int> Sp;
    vector<int> castle;
    vector<queue<tuple<int, int, int>>> PQ;
    char grid[1000][1000];
    bool visited[1000][1000];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> N >> M >> P;
    Sp = vector<int>(P);
    castle = vector<int>(P);
    PQ = vector<queue<tuple<int, int, int>>>(P);

    for (int &s : Sp)
        cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
            if (isdigit(grid[i][j])) {
                castle[grid[i][j] - '1']++;
                PQ[grid[i][j]-'1'].emplace(i, j, 0);
                visited[i][j] = true;
            }
        }
    }

    bfs();
    for (int c : castle)
        cout << c << ' ';
}
void BJ::bfs() {
    queue<tuple<int, int, int>> Q;

    int p = 0;
    int r, c, s;
    int canGo = 0;
    while (true) {
        queue<tuple<int, int, int>> Q;
        while (!PQ[p].empty()) {
            tie(r, c, s) = PQ[p].front();
            PQ[p].pop();

            for (int i = 0; i < 4; i++) {
                int R = r + dr[i];
                int C = c + dc[i];
                if (R < 0 || R >= N || C < 0 || C >= M) continue;
                if (visited[R][C] || grid[R][C] == '#') continue;
                if (isdigit(grid[R][C])) continue;
                if (s + 1 > Sp[grid[r][c]-'1']) continue;
                grid[R][C] = grid[r][c];
                visited[R][C] = true;
                castle[grid[r][c]-'1']++;
                if (s + 1 == Sp[grid[r][c]-'1'])
                    Q.emplace(R, C, 0);
                else
                    PQ[p].emplace(R, C, s + 1);
            }
        }
        if (Q.empty())
            canGo++;
        else
            canGo = 0;
        if (canGo == P)
            break;
        PQ[p] = Q;
        p = (p + 1) % P;
    }
}


signed main() {
    fastIO;

    BJ Q16920;
}