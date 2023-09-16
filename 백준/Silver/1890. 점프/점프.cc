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

int dp[100][100];

signed main() {
    fastIO;

    int N, game[100][100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> game[i][j];
    }

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0) continue;
            if (i == N-1 && j == N-1) break;
            if (i + game[i][j] < N)
                dp[i + game[i][j]][j] += dp[i][j];
            if (j + game[i][j] < N)
                dp[i][j + game[i][j]] += dp[i][j];
        }
    }

    cout << dp[N-1][N-1];
}