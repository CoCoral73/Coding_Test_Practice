#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, M;
    int **map;
    vector<pair<int, int>> virus;
    pair<int, int> *active;
    int blank = 0;
    int answer = INT32_MAX;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
public:
    BJ();
    void select_virus(int depth, int index);
    void spread_virus();
    void Q17142();
};

BJ::BJ() {
    cin >> N >> M;
    map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                blank++;
            else if (map[i][j] == 2)
                virus.emplace_back(i, j);
        }
    }
    active = new pair<int, int>[M];
}
void BJ::select_virus(int depth, int index) {
    if (depth == M) {
        spread_virus();
        return;
    }
    for (int i = index; i < virus.size(); i++) {
        active[depth] = virus[i];
        select_virus(depth+1, i+1);
    }
}
void BJ::spread_virus() {
    int **visit = new int *[N];
    for (int i = 0; i < N; i++) {
        visit[i] = new int[N];
        for (int j = 0; j < N; j++)
            visit[i][j] = INT32_MAX;
    }

    queue<pair<int, int>> Q;
    for (int i = 0; i < M; i++) {
        Q.push(active[i]);
        visit[active[i].first][active[i].second] = 0;
    }

    int MAX = 0, total = 0;
    int r, c;
    while (!Q.empty()) {
        tie(r, c) = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int R = r + dr[i];
            int C = c + dc[i];
            if (R < 0 || R >= N || C < 0 || C >= N)
                continue;
            if (map[R][C] == 1)
                continue;
            if (visit[R][C] > visit[r][c]+1) {
                if (map[R][C] == 0 && visit[R][C] == INT32_MAX)
                    total++;
                visit[R][C] = visit[r][c]+1;
                Q.emplace(R, C);
                if (map[R][C] == 0)
                    MAX = max(MAX, visit[R][C]);
            }
        }
    }
    if (total != blank)
        return;

    answer = min(answer, MAX);
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << visit[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    */
}
void BJ::Q17142() {
    if (answer == INT32_MAX)
        cout << -1;
    else
        cout << answer;
}

int main() {
    fastIO;

    BJ a;
    a.select_virus(0, 0);
    a.Q17142();
}