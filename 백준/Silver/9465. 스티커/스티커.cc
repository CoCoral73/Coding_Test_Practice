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

int T, n;
int sticker[2][100000];
int dp[2][100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> sticker[i][j];
            }
        }
        
        int answer = 0;
        
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        
        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];
        
        answer = max(dp[0][1], dp[1][1]);
        
        for (int i = 2; i < n; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
            answer = max(answer, max(dp[0][i], dp[1][i]));
        }
        
        cout << answer << '\n';
    }
}
