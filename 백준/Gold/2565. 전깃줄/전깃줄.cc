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
    vector<pii> lines;
    vector<int> dp;
public:
    BJ();
};

BJ::BJ() {
    cin >> N;
    lines = vector<pii>(N);
    dp = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].first >> lines[i].second;
        dp[i] = 1;
    }

    sort(lines.begin(), lines.end());

    int answer = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] + 1 > dp[i] && lines[j].second < lines[i].second)
                dp[i] = dp[j] + 1;
            answer = max(answer, dp[i]);
        }
    }

    cout << N - answer;
}

signed main() {
    BJ Q2565;
}