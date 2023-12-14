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
    int wN;
    int weight[31];
    int bN, bead;
    int dp[31][40001];
public:
    BJ();
    void solution();
};

BJ::BJ() {
    cin >> wN;
    int sum = 0;
    for (int i = 1; i <= wN; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    solution();

    cin >> bN;
    for (int i = 0; i < bN; i++) {
        cin >> bead;
        bool flag = false;
        for (int j = bead; j <= sum; j++) {
            if (j == bead && dp[wN][bead] == 1) { flag = true; break; }
            if (dp[wN][j] == 0) continue;
            if (dp[wN][j-bead] == 1) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Y " : "N ");
    }

}
void BJ::solution() {
    memset(dp, 0, sizeof(int)*40001);
    for (int i = 1; i <= wN; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= 40000; j++) {
            if (weight[i] > j)
                dp[i][j] = dp[i-1][j];
            else {
                if (weight[i] == j)
                    dp[i][j] = 1;
                else if (dp[i-1][j-weight[i]] == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
}

signed main(){
    fastIO;

    BJ Q2629;
}
