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
    int K;
    int V, E;
    set<int> *networks;
    set<int> Vset[2];
    bool *visited;
public:
    BJ();
    bool dfs(int now, bool included);
};

BJ::BJ() {
    cin >> K;
    int u, v;
    while (K--) {
        cin >> V >> E;
        networks = new set<int>[V+1];
        visited = new bool[V+1];
        memset(visited, 0, sizeof(bool)*V);
        while (E--) {
            cin >> u >> v;
            networks[u].emplace(v);
            networks[v].emplace(u);
        }

        int result = true;
        for (int i = 1; i <= V; i++) {
            if (visited[i]) continue;
            Vset[0].emplace(i);
            result = dfs(i, false);
            if (!result) break;
        }
        if (result)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        Vset[0].clear(); Vset[1].clear();
    }
}
bool BJ::dfs(int now, bool included) {
    visited[now] = true;
    int N = included ? 1 : 0;

    for (int n : networks[now]) {
        if (visited[n]) {
            if (Vset[N].find(n) != Vset[N].end()) { return false; }
            continue;
        }
        if (Vset[N].find(n) != Vset[N].end()) { return false; }
        Vset[!N].emplace(n);
        bool result = dfs(n, !included);
        if (!result) { return false; }
    }
    return true;
}

signed main(){
    fastIO;

    BJ a;
}
