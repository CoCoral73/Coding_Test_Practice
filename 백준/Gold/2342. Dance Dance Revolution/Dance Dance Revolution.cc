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
    vector<int> inputs;
    int size;
    int ***dp;
public:
    BJ();
    int solution(int x, int left, int right);
};

BJ::BJ() {
    int x;
    inputs.emplace_back(0);
    while (true) {
        cin >> x;
        inputs.emplace_back(x);
        if (x == 0) break;
    }
    size = inputs.size();

    dp = new int **[size];
    for (int i = 0; i < size; i++) {
        dp[i] = new int *[5];
        for (int j = 0; j < 5; j++) {
            dp[i][j] = new int[5];
            for (int k = 0; k < 5; k++)
                dp[i][j][k] = INT32_MAX;
        }
    }

    dp[0][0][0] = solution(0, 0, 0);
    cout << dp[0][0][0];
}
int BJ::solution(int x, int left, int right) {
    if (inputs[x+1] == 0)
        return 0;
    if (dp[x][left][right] != INT32_MAX)
        return dp[x][left][right];

    if (inputs[x+1] == left | inputs[x+1] == right) {
        dp[x][left][right] = solution(x+1, left, right) + 1;
    }
    else {
        int plus;
        if (left == 0) plus = 2;
        else {
            if (left % 2 == inputs[x+1] % 2)
                plus = 4;
            else
                plus = 3;
        }
        int next1 = solution(x+1, inputs[x+1], right) + plus;

        if (right == 0) plus = 2;
        else {
            if (right % 2 == inputs[x+1] % 2)
                plus = 4;
            else
                plus = 3;
        }
        int next2 = solution(x+1, left, inputs[x+1]) + plus;

        dp[x][left][right] = min(next1, next2);
    }
    return dp[x][left][right];
}

signed main() {
    fastIO;

    BJ Q2342;
}