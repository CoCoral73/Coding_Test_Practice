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
    int N;
    vector<pii> black, white;
    vector<pii> inuse_black, inuse_white;
    int ans1 = 0, ans2 = 0;
public:
    BJ();
    void backtracking_black(int start);
    void backtracking_white(int start);
};

BJ::BJ() {
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            if (x == 1) {
                if ((i + j) % 2 == 0)
                    black.emplace_back(i, j);
                else
                    white.emplace_back(i, j);
            }
        }
    }

    backtracking_black(0);
    backtracking_white(0);
    cout << ans1 + ans2;
}
void BJ::backtracking_black(int start) {
    ans1 = max(ans1, (int)(inuse_black.size()));

    for (int i = start; i < black.size(); i++) {
        bool flag = true;
        for (int j = 0; j < inuse_black.size(); j++) {
            if (abs(black[i].first - inuse_black[j].first) == abs(black[i].second - inuse_black[j].second)) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        inuse_black.emplace_back(black[i]);
        backtracking_black(i+1);
        inuse_black.pop_back();
    }
}
void BJ::backtracking_white(int start) {
    ans2 = max(ans2, (int)(inuse_white.size()));

    for (int i = start; i < white.size(); i++) {
        bool flag = true;
        for (int j = 0; j < inuse_white.size(); j++) {
            if (abs(white[i].first - inuse_white[j].first) == abs(white[i].second - inuse_white[j].second)) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        inuse_white.emplace_back(white[i]);
        backtracking_white(i+1);
        inuse_white.pop_back();
    }
}

signed main() {
    fastIO;

    BJ Q1799;
}