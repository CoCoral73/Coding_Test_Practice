#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N;
    vector<pair<int, int>> v;
    int answer = LONG_LONG_MAX;
public:
    BJ();
    void dfs(int bits, int start);
};

BJ::BJ() {
    cin >> N;
    v = vector<pair<int, int>>(N);
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }

    dfs(0, 0);
    cout << answer;
}
void BJ::dfs(int bits, int start) {
    if (start >= N) {
        if (bits == 0)
            return;
        int sour = 1, bitter = 0;
        for (int i = 0; i < N; i++) {
            if (bits & (1 << i)) {
                sour *= v[i].first;
                bitter += v[i].second;
            }
        }
        answer = min(answer, abs(sour - bitter));
        return;
    }

    dfs(bits | (1 << start), start + 1);
    dfs(bits, start + 1);
}

signed main() {
    fastIO;

    BJ Q2961;
}