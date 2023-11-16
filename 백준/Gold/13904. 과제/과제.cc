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
    int N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
public:
    BJ();
};

BJ::BJ() {
    cin >> N;

    int d, w;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        pq.emplace(w, d);
    }

    vector<int> v;
    int answer = 0;
    while (!pq.empty()) {
        bool flag = true;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= pq.top().second && i + 1 >= v[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            v.emplace_back(pq.top().second);
            sort(v.begin(), v.end());
            answer += pq.top().first;
        }
        pq.pop();
    }
    cout << answer;
}

signed main() {
    fastIO;

    BJ Q13904;
}