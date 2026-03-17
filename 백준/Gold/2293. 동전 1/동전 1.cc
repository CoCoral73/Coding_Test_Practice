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

int n, k;
vector<int> coins;
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        
        if (coin <= k) {
            coins.emplace_back(coin);
        }
    }
    
    for (int i = 0; i < coins.size(); i++) {
        dp[coins[i]] += 1;
        for (int j = coins[i] + 1; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    cout << dp[k];
}
