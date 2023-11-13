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
    priority_queue<int, vector<int>, greater<>> min_pq;
    priority_queue<int, vector<int>, less<>> max_pq;
public:
    BJ();
};

BJ::BJ() {
    cin >> N;

    int n;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> n;
        if (max_pq.empty()) max_pq.emplace(n);
        else if (min_pq.size() == max_pq.size()) max_pq.emplace(n);
        else min_pq.emplace(n);

        while (!min_pq.empty() && min_pq.top() < max_pq.top()) {
            int tmp = max_pq.top();
            max_pq.pop();
            max_pq.emplace(min_pq.top());
            min_pq.pop();
            min_pq.emplace(tmp);
        }
        cout << max_pq.top() << '\n';
    }
}

signed main() {
    fastIO;

    BJ Q1655;
}