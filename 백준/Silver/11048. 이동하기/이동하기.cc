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

int dp[1000][1000];

signed main() {
    int N, M;
    int grid[1000][1000];

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (i - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (i - 1 >= 0 && j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] += grid[i][j];
        }
    }

    cout << dp[N-1][M-1];
}