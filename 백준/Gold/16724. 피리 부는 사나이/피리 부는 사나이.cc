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
    pii **parent;
    int answer;
public:
    BJ();
    pii findParent(pii p);
    void unionParent(pii p1, pii p2);
};

BJ::BJ() {
    cin >> N >> M;
    answer = N*M;
    parent = new pii *[N];
    for (int i = 0; i < N; i++) {
        parent[i] = new pii[M];
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            parent[i][j] = {i, j};
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (parent[i][j] != make_pair(i, j)) continue;
            pii p;
            switch (grid[i][j]) {
                case 'U': p = findParent({i-1, j}); break;
                case 'D': p = findParent({i+1, j}); break;
                case 'L': p = findParent({i, j-1}); break;
                default: p = findParent({i, j+1});
            }
            if (p != make_pair(i, j)) {
                parent[i][j] = p;
                answer--;
            }
        }
    }
    cout << answer;
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
