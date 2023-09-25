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

struct node {
    vector<int> horse;
    int top;
    node() {
        top = -1;
        for (int i = 0; i <= 30; i++)
            horse.emplace_back(INT32_MAX);
    }
};

class BJ {
    int K;
    int W, H;
    int grid[200][200];
    node visit[200][200];
    int hr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int hc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> K;
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];
    }

    bfs();
}
void BJ::bfs() {
    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    visit[0][0].horse[0] = 0;
    visit[0][0].top = 0;

    int r, c, R, C;
    while (!Q.empty()) {
        tie(r, c) = Q.front();
        Q.pop();
        //cout << "(" << r << "," << c << ") :";
        for (int i = 0; i <= visit[r][c].top; i++) {
            int V = visit[r][c].horse[i];
            //cout << V << ' ';
            if (i + 1 <= K) {
                for (int j = 0; j < 8; j++) {
                    R = r + hr[j];
                    C = c + hc[j];
                    if (R < 0 || R >= H || C < 0 || C >= W)
                        continue;
                    if (grid[R][C] == 1)
                        continue;
                    if (visit[R][C].horse[i+1] > V + 1) {
                        visit[R][C].horse[i+1] = V + 1;
                        visit[R][C].top = max(visit[R][C].top, i + 1);
                        Q.emplace(R, C);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                R = r + dr[j];
                C = c + dc[j];
                if (R < 0 || R >= H || C < 0 || C >= W)
                    continue;
                if (grid[R][C] == 1)
                    continue;
                if (visit[R][C].horse[i] > V + 1) {
                    visit[R][C].horse[i] = V + 1;
                    visit[R][C].top = max(visit[R][C].top, i);
                    Q.emplace(R, C);
                }
            }
        }
        //cout << endl;
    }

    node answer = visit[H-1][W-1];
    if (answer.top == -1)
        cout << -1;
    else {
        int MIN = INT32_MAX;
        for (int i = 0; i <= answer.top; i++)
            MIN = min(MIN, answer.horse[i]);
        cout << MIN;
    }
}

signed main() {
    fastIO;
    BJ Q1600;
}