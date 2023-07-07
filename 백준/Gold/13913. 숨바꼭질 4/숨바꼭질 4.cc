#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct node {
    int loc;
    int time;
}NODE;

class BJ {
    int N, K;
    int answer = INT32_MAX;
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> N >> K;
}
void BJ::bfs() {
    if (N >= K) {
        cout << N-K << '\n';
        for (int i = N; i >= K; i--)
            cout << i << ' ';
        return;
    }
    pair<int, int> visit[200001];
    for (int i = 0; i < 200001; i++)
        visit[i] = {INT32_MAX, INT32_MAX};
    queue<NODE> Q;
    Q.push({N, 0});
    visit[N] = {0, N};
    while (!Q.empty()) {
        int X = Q.front().loc;
        int t = Q.front().time;
        Q.pop();

        if (X-1 >= 0) {
            if (X-1 == K) {
                if (answer > t+1) {
                    answer = t + 1;
                    visit[X-1] = {t+1, X};
                    continue;
                }
            }
            else if (t+1 < visit[X-1].first) {
                visit[X-1] = {t+1, X};
                Q.push({X-1, t+1});
            }
        }
        if (X+1 <= K) {
            if (X+1 == K) {
                if (answer > t+1) {
                    answer = t + 1;
                    visit[X+1] = {t+1, X};
                    continue;
                }
            }
            else if (t+1 < visit[X+1].first) {
                visit[X+1] = {t+1, X};
                Q.push({X+1, t+1});
            }
        }
        if (2*X <= 200000) {
            if (2*X == K) {
                if (answer > t+1) {
                    answer = t+1;
                    visit[2*X] = {t+1, X};
                    continue;
                }
            }
            else if (t+1 < visit[2*X].first) {
                visit[2*X] = {t+1, X};
                Q.push({2*X, t+1});
            }
        }
    }

    cout << answer << '\n';
    vector<int> route;
    int now = K;
    while (true) {
        route.insert(route.begin(), now);
        if (now == N)
            break;
        now = visit[now].second;
    }
    for (int i = 0; i < route.size(); i++)
        cout << route[i] << ' ';
}

int main() {
    fastIO;

    BJ a;
    a.bfs();
}