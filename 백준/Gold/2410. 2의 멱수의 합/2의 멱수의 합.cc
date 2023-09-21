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

class BJ {
    int N;
    vector<int> dp;
public:
    BJ();
    void solution();
};

BJ::BJ() {
    cin >> N;
    dp = vector<int>(N+1);
    solution();
    cout << dp[N];
}
void BJ::solution() {
    int power = 1;
    while (power <= N) {
        for (int i = 1; i <= N; i++) {
            if (power == 1)
                dp[i] = 1;
            else {
                if (power == i)
                    dp[i] = (dp[i] + 1) % 1000000000;
                else if (i - power > 0)
                    dp[i] = (dp[i] + dp[i-power]) % 1000000000;
            }
        }
        power *= 2;
    }
}

signed main() {
    fastIO;

    BJ a;
}