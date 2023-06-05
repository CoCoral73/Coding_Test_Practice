#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N, M;
    string *campus;
    bool** visited;
    pair<int, int> me;

    cin >> N >> M;
    campus = new string[N];
    visited = new bool*[N];
    for (int i = 0; i < N; i++) {
        cin >> campus[i];
        visited[i] = new bool[M];
        for (int j = 0; j < M; j++) {
            if (campus[i][j] == 'I')
                me = {i, j};
            visited[i][j] = false;
        }
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    queue<pair<int, int>> Q;
    visited[me.first][me.second] = true;
    Q.emplace(me);
    int result = 0;
    while (!Q.empty()) {
        int r,c;
        tie(r,c) = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int R = r + dr[i];
            int C = c + dc[i];
            if (R < 0 || R >= N || C < 0 || C >= M)
                continue;
            if (campus[R][C] == 'X' || visited[R][C])
                continue;
            visited[R][C] = true;
            Q.emplace(R, C);
            if (campus[R][C] == 'P')
                result++;
        }
    }

    if (result == 0)
        cout << "TT";
    else
        cout << result;
}