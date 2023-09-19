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

    int N, tmp;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            if (pq.size() < N)
                pq.emplace(tmp);
            else {
                if (pq.top() < tmp) {
                    pq.pop();
                    pq.emplace(tmp);
                }
            }
        }
    }

    cout << pq.top();
}