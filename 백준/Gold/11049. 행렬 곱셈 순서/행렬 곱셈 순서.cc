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
    vector<pair<int, int>> matrix;
    int dp[500][500];
public:
    BJ();
    void solution();
};

BJ::BJ() {
    cin >> N;
    matrix = vector<pair<int, int>>(N);
    for (pair<int, int> &m : matrix)
        cin >> m.first >> m.second;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INT32_MAX;
        }
    }

    solution();
    cout << dp[0][N-1];
}
void BJ::solution() {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1-i; j++) {
            for (int k = j; k < j + i + 1; k++)
                dp[j][j+i+1] = min(dp[j][j+i+1], dp[j][k] + dp[k+1][j+i+1] + matrix[j].first * matrix[k+1].first * matrix[j+i+1].second);
        }
    }
/*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << dp[i][j] << '\t';
        cout << endl;
    }
*/
}

signed main() {
    fastIO;
    BJ Q11049;
}