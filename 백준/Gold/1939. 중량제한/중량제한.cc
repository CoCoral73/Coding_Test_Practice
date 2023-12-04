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
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, M;
    int A, B, C;
    int src, dest;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<>> pq;
    int parent[10001];
    int answer = 0;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    while (M--) {
        cin >> A >> B >> C;
        pq.emplace(C, A, B);
    }

    cin >> src >> dest;

    while (!pq.empty()) {
        tie(C, A, B) = pq.top();
        pq.pop();

        unionParent(A, B);
        if (findParent(src) == findParent(dest)) {
            cout << C;
            return;
        }
    }
}
int BJ::findParent(int x) {
    if (parent[x] == x)
        return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
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

    BJ Q1939;
}
