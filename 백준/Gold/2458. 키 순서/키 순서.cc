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
    vector<int> small_next;
    vector<int> big_next;
    int smaller, bigger;
    bool visit;
    node() { smaller = 0; bigger = 0; visit = false; }
};

class BJ {
    int N, M;
    vector<node> graph;
    int answer;
public:
    BJ();
    void big_dfs(int o, int now);
    void small_dfs(int o, int now);
};

BJ::BJ() {
    cin >> N >> M;
    graph = vector<node>(N+1);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].big_next.emplace_back(b);
        graph[b].small_next.emplace_back(a);
    }

    answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            graph[j].visit = false;
        big_dfs(i, i);
        for (int j = 1; j <= N; j++)
            graph[j].visit = false;
        small_dfs(i, i);
        //cout << graph[i].bigger << ' ' << graph[i].smaller << endl;
        if (graph[i].bigger + graph[i].smaller == N-1)
            answer++;
    }

    cout << answer;
}
void BJ::big_dfs(int o, int now) {
    for (int x : graph[now].big_next) {
        if (graph[x].visit) continue;
        graph[o].bigger++;
        graph[x].visit = true;
        big_dfs(o, x);
    }
}
void BJ::small_dfs(long long o, long long now) {
    for (int x : graph[now].small_next) {
        if (graph[x].visit) continue;
        graph[o].smaller++;
        graph[x].visit = true;
        small_dfs(o, x);
    }
}

signed main() {
    fastIO;

    BJ a;
}