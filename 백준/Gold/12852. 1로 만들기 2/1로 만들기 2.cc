//
//  main.cpp
//  CppPractice
//
//  Created by 김정원 on 3/13/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N;
int dp[1000001];

void dfs(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(dp, dp + 1000001, INF);
    
    cin >> N;
    
    dp[1] = 0;
    for (int i = 1; i < N; i++) {
        if (i * 3 <= N) {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }
        
        if (i * 2 <= N) {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
        
        if (i + 1 <= N) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
    }
    
    cout << dp[N] << '\n';
    dfs(N);
}

void dfs(int x) {
    cout << x << ' ';
    
    if (x == 1) { return; }
    
    int y = x - 1;
    
    if (x % 3 == 0 && dp[y] > dp[x / 3]) {
        y = x / 3;
    }
    
    if (x % 2 == 0 && dp[y] > dp[x / 2]) {
        y = x / 2;
    }

    dfs(y);
}
