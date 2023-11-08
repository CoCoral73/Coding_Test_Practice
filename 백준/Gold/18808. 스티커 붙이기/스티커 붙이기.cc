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
#include <memory.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, M, K;
    int stickers[100][10][10];
    vector<pair<int, int>> stickers_RC;
    int laptop[40][40];
    int answer = 0;
public:
    BJ();
    void simulation();
    bool check_and_act(int a, int b, int i, int dir);
};

BJ::BJ() {
    cin >> N >> M >> K;
    int R, C;
    for (int i = 0; i < K; i++) {
        cin >> R >> C;
        stickers_RC.emplace_back(R, C);
        for (int a = 0; a < R; a++) {
            for (int b = 0; b < C; b++)
                cin >> stickers[i][a][b];
        }
    }
    memset(laptop, 0, sizeof(int)*1600);

    simulation();
    cout << answer;
}
void BJ::simulation() {
    for (int i = 0; i < K; i++) {
        bool flag = false;
        for (int a = 0; a < N; a++) {
            if (stickers_RC[i].first > N || stickers_RC[i].second > M) break;
            if (N - a < stickers_RC[i].first) break;
            for (int b = 0; b < M; b++) {
                if (M - b < stickers_RC[i].second) break;
                flag = check_and_act(a, b, i, 0);
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) continue;

        for (int a = 0; a < N; a++) {
            if (stickers_RC[i].first > M || stickers_RC[i].second > N) break;
            if (N - a < stickers_RC[i].second) break;
            for (int b = 0; b < M; b++) {
                if (M - b < stickers_RC[i].first) break;
                flag = check_and_act(a, b, i, 1);
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) continue;

        for (int a = 0; a < N; a++) {
            if (stickers_RC[i].first > N || stickers_RC[i].second > M) break;
            if (N - a < stickers_RC[i].first) break;
            for (int b = 0; b < M; b++) {
                if (M - b < stickers_RC[i].second) break;
                flag = check_and_act(a, b, i, 2);
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) continue;

        for (int a = 0; a < N; a++) {
            if (stickers_RC[i].first > M || stickers_RC[i].second > N) break;
            if (N - a < stickers_RC[i].second) break;
            for (int b = 0; b < M; b++) {
                if (M - b < stickers_RC[i].first) break;
                flag = check_and_act(a, b, i, 3);
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) continue;
    }
}
bool BJ::check_and_act(int a, int b, int i, int dir) {
    int R, C;
    tie(R, C) = stickers_RC[i];
    if (dir == 0) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (stickers[i][r][c] == 1 && laptop[a + r][b + c] == 1)
                    return false;
            }
        }
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (stickers[i][r][c] == 1) {
                    laptop[a + r][b + c] = 1;
                    answer++;
                }
            }
        }
        return true;
    }
    if (dir == 1) {
        for (int r = 0; r < C; r++) {
            for (int c = 0; c < R; c++) {
                if (stickers[i][R - c - 1][r] == 1 && laptop[a + r][b + c] == 1)
                    return false;
            }
        }
        for (int r = 0; r < C; r++) {
            for (int c = 0; c < R; c++) {
                if (stickers[i][R - c - 1][r] == 1) {
                    laptop[a + r][b + c] = 1;
                    answer++;
                }
            }
        }
        return true;
    }
    if (dir == 2) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (stickers[i][R - r - 1][C - c - 1] == 1 && laptop[a + r][b + c] == 1)
                    return false;
            }
        }
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (stickers[i][R - r - 1][C - c - 1] == 1) {
                    laptop[a + r][b + c] = 1;
                    answer++;
                }
            }
        }
        return true;
    }
    if (dir == 3) {
        for (int r = 0; r < C; r++) {
            for (int c = 0; c < R; c++) {
                if (stickers[i][c][C - r - 1] == 1 && laptop[a + r][b + c] == 1)
                    return false;
            }
        }
        for (int r = 0; r < C; r++) {
            for (int c = 0; c < R; c++) {
                if (stickers[i][c][C - r - 1] == 1) {
                    laptop[a + r][b + c] = 1;
                    answer++;
                }
            }
        }
        return true;
    }
}

signed main() {
    fastIO;

    BJ Q18808;
}