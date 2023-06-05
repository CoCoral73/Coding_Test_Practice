#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    int **MAP, **distance;
    pair<int, int> dest;

    cin >> n >> m;
    MAP = new int*[n];
    distance = new int*[n];
    for (int i = 0; i < n; i++) {
        MAP[i] = new int[m];
        distance[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
                dest = {i, j};
            distance[i][j] = INT32_MAX;
            if (MAP[i][j] == 0)
                distance[i][j] = 0;
        }
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    queue<pair<int, int>> Q;
    distance[dest.first][dest.second] = 0;
    Q.emplace(dest);
    while (!Q.empty()) {
        int r, c;
        tie(r, c) = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int R = r + dr[i];
            int C = c + dc[i];
            if (R < 0 || R >= n || C < 0 || C >= m)
                continue;
            if (MAP[R][C] == 0 || distance[R][C] <= distance[r][c]+1)
                continue;
            distance[R][C] = distance[r][c]+1;
            Q.emplace(R, C);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (distance[i][j] == INT32_MAX)
                distance[i][j] = -1;
            cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }
}