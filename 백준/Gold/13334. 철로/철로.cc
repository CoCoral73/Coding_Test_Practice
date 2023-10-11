#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

signed main() {
    fastIO;

    int n, h, o, d;
    vector<pair<int, int>> v;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> o;
        v.push_back({min(h, o), max(h, o)});
    }
    cin >> d;

    for (int i = 0; i < n; i++)
        if (v[i].second - v[i].first <= d) pq1.push(v[i]);

    if (pq1.size() == 0) {
        cout << 0;
        exit(0);
    }

    int s = pq1.top().second - d, e = pq1.top().second;
    unsigned long MAX = 1;
    pq2.push(pq1.top());
    pq1.pop();

    while (!pq1.empty()) {
        pair<int, int> top = pq1.top();
        pq1.pop();

        if (top.second > e) {
            MAX = max(MAX, pq2.size());
            while (!pq2.empty() && pq2.top().first < top.second - d) {
                //cout << top.second << ' ' << pq2.top().first << endl;
                pq2.pop();
            }
            e = top.second;
        }
        pq2.push(top);
    }
    MAX = max(MAX, pq2.size());

    cout << MAX;
}