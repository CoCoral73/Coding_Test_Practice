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
    int n, m;
    int *parent;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> n >> m;

    parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        int pa = findParent(a);
        int pb = findParent(b);
        if (i % 2 == 1) {
            if (pa == pb) {
                cout << i;
                return;
            }
        }
        else {
            if (pa == pb) {
                cout << i;
                return;
            }
        }
        unionParent(a, b);
    }
    cout << 0;
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

    BJ a;
}
