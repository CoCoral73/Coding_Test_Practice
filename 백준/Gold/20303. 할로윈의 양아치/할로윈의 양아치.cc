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
    int N, M, K;
    vector<pii> candy;
    vector<int> parent;
    vector<int> dp;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
    int bottomup();
};

BJ::BJ() {
    cin >> N >> M >> K;

    candy = vector<pii>(N+1);
    parent = vector<int>(N+1);
    dp = vector<int>(K);
    for (int i = 1, c; i <= N; i++) {
        cin >> c;
        candy[i] = {1, c};
        parent[i] = i;
    }

    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        unionParent(a, b);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] != i) {
            int p = findParent(i);
            candy[p].first += candy[i].first;
            candy[p].second += candy[i].second;
        }
    }

    cout << bottomup();
}
int BJ::findParent(int x) {
    if (parent[x] == x)
        return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
}
void BJ::unionParent(int x, int y) {
    int px = findParent(x), py = findParent(y);
    if (px <= py)
        parent[py] = px;
    else
        parent[px] = py;
}
int BJ::bottomup() {
    int MAX = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] != i) continue;
        for (int j = K-1; j >= candy[i].first; j--) {
            dp[j] = max(dp[j], dp[j-candy[i].first] + candy[i].second);
            MAX = max(MAX, dp[j]);
        }
    }
    return MAX;
}

signed main() {
    fastIO;

    BJ Q20303;
}