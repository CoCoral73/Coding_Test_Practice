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
        return a.second < b.second;
    }
};

signed main() {
    fastIO;

    int N, K, M, V, C;
    vector<pair<int, int>> jewel;
    vector<int> bag;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        jewel.emplace_back(M, V);
    }
    sort(jewel.begin(), jewel.end());

    for (int i = 0; i < K; i++) {
        cin >> C;
        bag.emplace_back(C);
    }
    sort(bag.begin(), bag.end());

    int answer = 0, index = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 0; i < K; i++) {
        while (index < N && jewel[index].first <= bag[i]) {
            pq.push(jewel[index]);
            index++;
        }
        if (!pq.empty()) {
            answer += pq.top().second;
            pq.pop();
        }
    }
    cout << answer;
}