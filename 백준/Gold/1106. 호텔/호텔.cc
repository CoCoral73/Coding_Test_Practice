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
//#define int long long
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int C, N;
    pii info[21];
    int dp[100001];
public:
    BJ();
    int solution();
};

BJ::BJ() {
    cin >> C >> N;
    int cost, customer;
    for (int i = 1; i <= N; i++) {
        cin >> cost >> customer;
        info[i] = {cost, customer};
    }

    cout << solution();
}
int BJ::solution() {
    int answer = INT32_MAX;
    memset(dp, 0, sizeof(int)*100001);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 100000; j++) {
            if (info[i].first > j) continue;
            dp[j] = max(dp[j], dp[j-info[i].first] + info[i].second);
            if (dp[j] >= C)
                answer = min(answer, j);
        }
    }
    return answer;
}

signed main(){
    fastIO;

    BJ Q1106;
}
