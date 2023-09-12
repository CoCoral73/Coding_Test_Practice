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

    int N, a, b, MIN = 500000, MAX = 0;
    cin >> N;

    vector<int> line(500001);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line[a] = b;
        MAX = max(MAX, max(a, b));
        MIN = min(MIN, a);
    }

    vector<int> result, dp(500001);
    result.emplace_back(MIN);
    dp[MIN] = 1;
    for (int i = MIN+1; i <= MAX; i++) {
        if (line[i] == 0) continue;
        if (line[result.back()] < line[i]) {
            result.emplace_back(i);
            dp[i] = result.size();
        }
        else {
            int s = 0, e = result.size()-1;
            int index;
            while (s <= e) {
                int m = (s + e) / 2;
                if (line[result[m]] >= line[i]) {
                    index = m;
                    e = m - 1;
                }
                else
                    s = m + 1;
            }
            result[index] = i;
            dp[i] = index+1;
        }
    }

    int answer = result.size(), last = 500001;
    cout << N - answer << '\n';
    vector<bool> A(MAX+1);
    for (int i = MAX; i >= 1; i--) {
        if (line[i] != 0 && line[i] < last && dp[i] == answer) {
            last = line[i];
            answer--;
            A[i] = true;
        }
    }
    for (int i = 1; i <= MAX; i++)
        if (!A[i] && line[i])
            cout << i << '\n';
}