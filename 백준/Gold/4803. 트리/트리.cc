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
    int n, m;
    int a, b;
    int parent[501];
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    int case_n = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            int pa = findParent(a);
            int pb = findParent(b);
            if (pa == pb)
                unionParent(0, pa);
            else
                unionParent(a, b);
        }

        set<int> roots;
        for (int i = 1; i <= n; i++) {
            int p = findParent(i);
            if (p != 0)
                roots.emplace(p);
        }

        cout << "Case " << case_n << ": ";
        int size = roots.size();
        if (size > 1)
            cout << "A forest of " << size << " trees.\n";
        else if (size == 1)
            cout << "There is one tree.\n";
        else
            cout << "No trees.\n";
        case_n++;
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

    BJ Q4803;
}
