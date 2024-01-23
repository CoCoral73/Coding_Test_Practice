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
    int T;
    int n, m;
    vector<int> A, B;
    vector<int> sum1, sum2;
    map<int, int> As, Bs;
    int answer = 0;
public:
    BJ();
};

BJ::BJ() {
    cin >> T;

    cin >> n;
    for (int i = 0, x, s = 0; i < n; i++) {
        cin >> x;
        A.emplace_back(x);
        s += x;
        sum1.emplace_back(s);
    }

    cin >> m;
    for (int i = 0, x, s = 0; i < m; i++) {
        cin >> x;
        B.emplace_back(x);
        s += x;
        sum2.emplace_back(s);
    }

    for (int i = 0; i < n; i++) {
        if (As.find(sum1[i]) != As.end())
            As[sum1[i]]++;
        else As[sum1[i]] = 1;

        for (int j = 0; j < i; j++) {
            int sum = sum1[i] - sum1[j];
            if (As.find(sum) != As.end())
                As[sum]++;
            else As[sum] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        if (Bs.find(sum2[i]) != Bs.end())
            Bs[sum2[i]]++;
        else Bs[sum2[i]] = 1;
        for (int j = 0; j < i; j++) {
            int sum = sum2[i] - sum2[j];
            if (Bs.find(sum) != Bs.end())
                Bs[sum]++;
            else Bs[sum] = 1;
        }
    }

    for (auto it = As.begin(); it != As.end(); it++) {
        int key = it->first;
        if (Bs.find(T-key) != Bs.end())
            answer += it->second * Bs[T-key];
    }

    cout << answer;
}

signed main() {
    fastIO;

    BJ Q2143;
}