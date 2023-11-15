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
public:
    BJ();
};

BJ::BJ() {
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<>> pq;
    int a;

    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.emplace(a);
    }

    while (m--) {
        int n1 = pq.top(); pq.pop();
        int n2 = pq.top(); pq.pop();
        pq.emplace(n1 + n2);
        pq.emplace(n1 + n2);
    }

    int answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}

signed main() {
    fastIO;

    BJ Q15903;
}