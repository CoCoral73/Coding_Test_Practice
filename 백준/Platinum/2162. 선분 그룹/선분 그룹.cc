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
    int N;
    vector<pair<pii, pii>> xy;
    int parent[3001];
public:
    BJ();
    int ccw(pii d1, pii d2, pii d3);
    bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2);
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> N;

    xy = vector<pair<pii, pii>>(N+1);
    int x1, y1, x2, y2;
    for (int i = 1; i <= N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        xy[i].first = make_pair(x1, y1);
        xy[i].second = make_pair(x2, y2);
        parent[i] = i;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (isIntersect(xy[i], xy[j]))
                unionParent(i, j);
        }
    }

    set<int> group;
    multiset<int> count;
    int MAX = 0;
    for (int i = 1; i <= N; i++) {
        group.emplace(findParent(i));
        count.emplace(findParent(i));
    }

    set<int>::iterator iter;
    for (iter = group.begin(); iter != group.end(); iter++)
        MAX = max(MAX, (int)count.count(*iter));
    cout << group.size() << '\n' << MAX;
}
int BJ::ccw(pii d1, pii d2, pii d3) {
    int rst = d1.first*d2.second+d2.first*d3.second+d3.first*d1.second;
    rst -= (d2.first*d1.second+d3.first*d2.second+d1.first*d3.second);
    if (rst > 0)
        return 1;
    else if (rst == 0)
        return 0;
    return -1;
}
bool BJ::isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {
    int ccw1 = ccw(l1.first, l1.second, l2.first);
    int ccw2 = ccw(l1.first, l1.second, l2.second);
    int ccw3 = ccw(l2.first, l2.second, l1.first);
    int ccw4 = ccw(l2.first, l2.second, l1.second);

    if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0) {
        if (l1.first.first == l1.second.first) {
            int max1 = max(l1.first.second, l1.second.second);
            int min1 = min(l1.first.second, l1.second.second);
            int max2 = max(l2.first.second, l2.second.second);
            int min2 = min(l2.first.second, l2.second.second);
            if (max1 >= min2 && max2 >= min1)
                return true;
            else
                return false;
        }
        int max1 = max(l1.first.first, l1.second.first);
        int min1 = min(l1.first.first, l1.second.first);
        int max2 = max(l2.first.first, l2.second.first);
        int min2 = min(l2.first.first, l2.second.first);
        if (max1 >= min2 && max2 >= min1)
            return true;
        return false;
    }
    if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0)
        return true;
    return false;
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

    BJ Q2162;
}
