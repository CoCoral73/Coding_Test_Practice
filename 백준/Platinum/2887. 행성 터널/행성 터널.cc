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

bool compare(const pii &a, const pii &b) {
    return a.second < b.second;
}

class BJ {
    int N;
    vector<int> parent;
    vector<pii> X, Y, Z;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    int answer = 0;
public:
    BJ();
    void unionParent(int a, int b);
    int findParent(int a);
};

BJ::BJ() {
    cin >> N;
    int x, y, z;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        X.emplace_back(i, x);
        Y.emplace_back(i, y);
        Z.emplace_back(i, z);
        parent.emplace_back(i);
    }

    sort(X.begin(), X.end(), compare);
    sort(Y.begin(), Y.end(), compare);
    sort(Z.begin(), Z.end(), compare);
    for (int i = 0; i < N-1; i++) {
        pq.push({abs(X[i].second - X[i+1].second), {X[i].first, X[i+1].first}});
        pq.push({abs(Y[i].second - Y[i+1].second), {Y[i].first, Y[i+1].first}});
        pq.push({abs(Z[i].second - Z[i+1].second), {Z[i].first, Z[i+1].first}});
    }

    int connect = 0, cost, a, b;
    while (connect < N-1) {
        cost = pq.top().first;
        tie(a, b) = pq.top().second;
        pq.pop();

        if (findParent(a) == findParent(b)) continue;
        unionParent(a, b);
        answer += cost;
        connect++;
    }

    cout << answer;
}
void BJ::unionParent(int a, int b) {
    int pa = findParent(a), pb = findParent(b);
    if (pa <= pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}
int BJ::findParent(int a) {
    if (parent[a] == a)
        return a;
    parent[a] = findParent(parent[a]);
    return parent[a];
}

signed main() {
    BJ Q2887;
}