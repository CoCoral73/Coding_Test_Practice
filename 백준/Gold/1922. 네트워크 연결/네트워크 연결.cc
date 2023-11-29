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
    vector<pair<int, int> >adj[10001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    bool visited[10001];
public:
    BJ();
};

BJ::BJ() {
    cin >> N >> M;
    memset(visited, 0, sizeof(bool)*N);
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }

    visited[1] = true;
    for (pair<int, int> p : adj[1])
        pq.emplace(p);

    int answer = 0;
    while (!pq.empty()) {
        tie(c, b) = pq.top();
        pq.pop();
        if (visited[b]) continue;
        visited[b] = true;
        answer += c;
        for (pair<int, int> p : adj[b]) {
            if (visited[p.second]) continue;
            pq.emplace(p);
        }
    }
    cout << answer;
}

signed main(){
    fastIO;

    BJ a;
}
