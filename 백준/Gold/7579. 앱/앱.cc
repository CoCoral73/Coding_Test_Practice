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
    int N, M;
    int A[101];
    int c[101];
    int DP[101][10001];
public:
    BJ();
    int solution();
};

BJ::BJ() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> c[i];

    cout << solution();
}
int BJ::solution() {
    int answer = INT32_MAX;
    memset(DP, 0, sizeof(int)*10001);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 10001; j++){
            if (c[i] > j)
                DP[i][j] = DP[i-1][j];
            else {
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-c[i]] + A[i]);
                if (DP[i][j] >= M)
                    answer = min(answer, j);
            }
        }
    }
    return answer;
}

signed main(){
    fastIO;

    BJ Q7579;
}
