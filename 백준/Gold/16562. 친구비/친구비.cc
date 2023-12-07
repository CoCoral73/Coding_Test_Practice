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
    int N, M, k;
    vector<int> A;
    int parent[10001];
    bool visited[10001];
    int answer = 0;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> N >> M >> k;

    A = vector<int>(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        parent[i] = i;
        visited[i] = false;
    }

    int v, w;
    while (M--) {
        cin >> v >> w;
        unionParent(v, w);
    }

    for (int i = 1; i <= N; i++) {
        int p = findParent(i);
        if (visited[p]) continue;
        answer += A[p];
        visited[p] = true;
    }

    if (answer > k)
        cout << "Oh no";
    else
        cout << answer;
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
    if (A[px] <= A[py])
        parent[py] = px;
    else
        parent[px] = py;
}

signed main(){
    fastIO;

    BJ Q16562;
}
