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
    fastIO;

    string str1, str2;
    cin >> str1 >> str2;

    int size1 = str1.size(), size2 = str2.size();
    int dp[size1+1][size2+1];
    for (int i = 0; i <= size1; i++)
        for (int j = 0; j <= size2; j++)
            dp[i][j] = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (str1[i] == str2[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    int len = dp[size1][size2], p1 = size1, p2 = size2;
    cout << len << '\n';

    vector<char> answer;
    while (len >= 1) {
        if (str1[p1-1] == str2[p2-1]) {
            answer.emplace_back(str1[p1-1]);
            p1--, p2--;
            len--;
        }
        else {
            if (dp[p1-1][p2] == dp[p1][p2])
                p1--;
            else
                p2--;
        }
    }
    for (int i = answer.size()-1; i >= 0; i--)
        cout << answer[i];
}