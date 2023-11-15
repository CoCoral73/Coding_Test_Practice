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
    int T, M;
public:
    BJ();
};

BJ::BJ() {
    cin >> T;
    int a;
    while (T--) {
        cin >> M;
        priority_queue<int, vector<int>, greater<>> big_pq;
        priority_queue<int, vector<int>, less<>> small_pq;
        deque<int> answer;
        for (int i = 1; i <= M; i++) {
            cin >> a;
            if (big_pq.size() == small_pq.size())
                small_pq.emplace(a);
            else
                big_pq.emplace(a);
            while (!big_pq.empty() && big_pq.top() < small_pq.top()) {
                int big = big_pq.top(); big_pq.pop();
                int small = small_pq.top(); small_pq.pop();
                big_pq.emplace(small);
                small_pq.emplace(big);
            }
            if (i % 2 == 1)
                answer.emplace_back(small_pq.top());
        }
        cout << answer.size() << '\n';
        while (!answer.empty()) {
            for (int i = 0; i < 10 && !answer.empty(); i++) {
                cout << answer.front() << ' ';
                answer.pop_front();
            }
            cout << '\n';
        }
    }
}

signed main() {
    fastIO;

    BJ Q2696;
}