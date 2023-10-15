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



signed main() {
    fastIO;

    int t, n, x, y;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        queue<pair<int, int>> Q;
        vector<pair<int, int>> v(n+2);
        vector<bool> beer(n+2);
        for (int j = 0; j < n + 2; j++) {
            cin >> x >> y;
            v[j] = {x, y};
            beer[j] = false;
        }

        Q.emplace(v[0]);
        beer[0] = 0;
        while (!Q.empty()) {
            tie(x, y) = Q.front();
            Q.pop();

            for (int j = 1; j < n + 2; j++) {
                int distance = abs(v[j].first - x) + abs(v[j].second - y);
                if (distance > 1000 || beer[j])
                    continue;
                beer[j] = true;
                Q.emplace(v[j]);
            }
        }
        if (beer[n+1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }

}