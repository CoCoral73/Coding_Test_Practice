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
    int dp[100][10][1024];
    int answer = 0;
public:
    BJ();
    int solution(int depth, int n, int bit);
};

BJ::BJ() {
    cin >> N;

    memset(dp, 0, sizeof(int)*1024000);

    for (int i = 1; i <= 9; i++) {
        answer += solution(0, i, 1 << i);
        answer %= 1000000000;
    }

    cout << answer;
}
int BJ::solution(int depth, int n, int bit) {
    if (dp[depth][n][bit] != 0) return dp[depth][n][bit];
    if (depth == N-1) {
        if (bit == 1023)
            return 1;
        else
            return 0;
    }

    int result = 0;
    if (n - 1 >= 0) {
        result += solution(depth+1, n-1, bit | (1 << (n-1)));
    }
    if (n + 1 <= 9) {
        result += solution(depth+1, n+1, bit | (1 << (n+1)));
    }

    result %= 1000000000;
    dp[depth][n][bit] = result;
    return result;
}

signed main(){
    fastIO;

    BJ Q1562;
}
