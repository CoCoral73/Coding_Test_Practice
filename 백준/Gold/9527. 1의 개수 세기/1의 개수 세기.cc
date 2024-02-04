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
    int A, B;
    vector<int> sum;
public:
    BJ();
    int solution(int x);
};

BJ::BJ() {
    cin >> A >> B;

    sum.emplace_back(1);
    for (int i = 1, n = 2; ; i++, n *= 2) {
        if (B <= n) break;
        sum.emplace_back(sum[i-1]*2 + n);
    }

    cout << solution(B) - solution(A-1);
}
int BJ::solution(int x) {
    if (x <= 0) return 0;

    int i = 0, n = 1;
    while (true) {
        if (n <= x && x < n*2) break;
        i++;
        n *= 2;
    }
    if (x == 2*n - 1) return sum[i];
    else return sum[i-1] + (x-n+1) + solution(x-n);
}

signed main() {
    fastIO;

    BJ Q9527;
}