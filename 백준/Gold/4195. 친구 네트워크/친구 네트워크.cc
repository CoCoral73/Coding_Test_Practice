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
    int T, F;
    vector<int> parent;
    vector<int> count;
    map<string, int> info;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> T;

    string x, y;
    while (T--) {
        cin >> F;
        parent.clear();
        count.clear();
        info.clear();
        int n = 0;
        while (F--) {
            cin >> x >> y;
            if (info.find(x) == info.end()) {
                info[x] = n;
                count.emplace_back(1);
                parent.emplace_back(n);
                n++;
            }
            if (info.find(y) == info.end()) {
                info[y] = n;
                count.emplace_back(1);
                parent.emplace_back(n);
                n++;
            }
            int nx = info[x], ny = info[y];
            int px = findParent(nx), py = findParent(ny);
            if (px != py) {
                count[min(px, py)] += count[max(px, py)];
            }
            unionParent(nx, ny);
            cout << count[min(px, py)] << '\n';
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
    if (px <= py) {
        parent[py] = px;
    }
    else {
        parent[px] = py;
    }
}

signed main(){
    fastIO;

    BJ a;
}
