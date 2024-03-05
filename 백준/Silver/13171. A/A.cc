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

const int MOD = 1000000007;

class BJ {
    int A, X;
public:
    BJ();
    int powering(int x);
};

BJ::BJ() {
    cin >> A;
    cin >> X;

    A %= MOD;
    cout << powering(X);
}
int BJ::powering(int x) {
    if (x == 1)
        return A;
    int p = powering(x/2);
    if (x % 2 == 0) {
        return (p*p) % MOD;
    }
    else {
        return (((p*p) % MOD) * A) % MOD;
    }
}

signed main() {
    fastIO;

    BJ Q13171;
}