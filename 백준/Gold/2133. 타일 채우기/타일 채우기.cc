#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0;
        return 0;
    }
    vector<int> dp = {0, 3, 11};
    for (int i = 3; i <= N/2; i++)
        dp.emplace_back(dp[i-1]*4 - dp[i-2]);
    cout << dp[N/2];
}
