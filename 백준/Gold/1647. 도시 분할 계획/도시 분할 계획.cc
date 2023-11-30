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
    int parent[100001];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    int answer = 0;
    int MAX = 0;
public:
    BJ();
    void kruskal();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> N >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        pq.emplace(c, a, b);
        parent[a] = a;
        parent[b] = b;
    }

    kruskal();
    cout << answer - MAX;
}
void BJ::kruskal() {
    int a, b, c;
    while (!pq.empty()) {
        tie(c, a, b) = pq.top();
        pq.pop();

        if (findParent(a) == findParent(b)) continue;
        unionParent(a, b);
        answer += c;
        MAX = max(MAX, c);
    }
}
int BJ::findParent(int x) {
    if (parent[x] == x)
        return x;
    return findParent(parent[x]);
}
void BJ::unionParent(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);
    if (px <= py)
        parent[py] = px;
    else
        parent[px] = py;
}

signed main(){
    fastIO;

    BJ a;
}
