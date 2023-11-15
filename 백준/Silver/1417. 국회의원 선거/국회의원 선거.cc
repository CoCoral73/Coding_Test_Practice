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
    int dasom;
    priority_queue<int, vector<int>, less<>> pq;
public:
    BJ();
};

BJ::BJ() {
    cin >> N;
    cin >> dasom;
    int other;
    while (--N) {
        cin >> other;
        pq.emplace(other);
    }

    int answer = 0;
    while (!pq.empty() && pq.top() >= dasom) {
        int top = pq.top(); pq.pop();
        dasom += 1;
        answer += 1;
        pq.emplace(top - 1);
    }
    cout << answer;
}

signed main() {
    fastIO;

    BJ Q1417;
}