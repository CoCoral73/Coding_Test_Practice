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
    int N, M;
    vector<pair<int, int>> routes[100001];
    bool visited[100001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int answer = 0;
    int MAX = 0;
public:
    BJ();
    void prim(int start);
};

BJ::BJ() {
    cin >> N >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        routes[a].emplace_back(c, b);
        routes[b].emplace_back(c, a);
        visited[a] = false;
        visited[b] = false;
    }

    prim(a);
    cout << answer - MAX;
}
void BJ::prim(int start) {
    visited[start] = true;
    for (pair<int, int> p : routes[start]) {
        pq.emplace(p);
    }

    int edge = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        if (visited[top.second]) continue;
        visited[top.second] = true;
        answer += top.first;
        MAX = max(MAX, top.first);
        if (edge == N-1) break;

        for (pair<int, int> p : routes[top.second]) {
            if (visited[p.second]) continue;
            pq.emplace(p);
        }
    }
}

signed main(){
    fastIO;

    BJ a;
}
