#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <memory.h>
#define int long long
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, M;
    char grid[1000][1000];
    bool visited[1000][1000];
    pii **parent;
public:
    BJ();
    void dfs(int r, int c);
    pii findParent(pii p);
    void unionParent(pii p1, pii p2);
};

BJ::BJ() {
    cin >> N >> M;
    parent = new pii *[N];
    for (int i = 0; i < N; i++) {
        parent[i] = new pii[M];
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
            parent[i][j] = {i, j};
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            dfs(i, j);
        }
    }

    set<pii> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            s.emplace(findParent({i, j}));
    }
    cout << s.size();
}
void BJ::dfs(int r, int c) {
    int dr, dc;
    switch (grid[r][c]) {
        case 'U': dr = -1, dc = 0; break;
        case 'D': dr = 1, dc = 0; break;
        case 'L': dr = 0, dc = -1; break;
        default: dr = 0, dc = 1; break;
    }
    visited[r][c] = true;
    if (findParent({r+dr, c+dc}) != findParent({r, c}))
        parent[r][c] = {r+dr, c+dc};
    if (visited[r+dr][c+dc])
        return;
    dfs(r+dr, c+dc);
}
pii BJ::findParent(pii p) {
    int r = p.first, c = p.second;
    if (parent[r][c] == make_pair(r, c))
        return {r, c};
    parent[r][c] = findParent(parent[r][c]);
    return parent[r][c];
}
void BJ::unionParent(pii p1, pii p2) {
    pii px = findParent(p1);
    pii py = findParent(p2);
    parent[py.first][py.second] = px;
}

signed main(){
    fastIO;

    BJ Q16724;
}
