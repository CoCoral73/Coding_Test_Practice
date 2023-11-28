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
#include <cctype>
#include <memory.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

signed main(){
    fastIO;

    int N, M;
    cin >> N >> M;

    pair<int, int> *dict = new pair<int, int>[1000001];
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    for (int i = 0; i < N; i++) {
        int before = i - 1 < 0 ? nums[N-1] : nums[i-1];
        int next = i + 1 >= N ? nums[0] : nums[i+1];
        dict[nums[i]] = {before, next};
    }

    string cmd;
    int i, j;
    while (M--) {
        cin >> cmd >> i;
        if (cmd == "BN") {
            cin >> j;
            int next = dict[i].second;
            cout << next << '\n';
            dict[j] = {i, next};
            dict[i].second = j;
            dict[next].first = j;
        }
        else if (cmd == "BP") {
            cin >> j;
            int before = dict[i].first;
            cout << before << '\n';
            dict[j] = {before, i};
            dict[i].first = j;
            dict[before].second = j;
        }
        else if (cmd == "CN") {
            int next = dict[i].second;
            cout << next << '\n';
            dict[i].second = dict[next].second;
            dict[dict[next].second].first = i;
        }
        else {
            int before = dict[i].first;
            cout << before << '\n';
            dict[i].first = dict[before].first;
            dict[dict[before].first].second = i;
        }
    }
}
