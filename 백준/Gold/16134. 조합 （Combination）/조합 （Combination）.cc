#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const long long MOD = 1000000007;

long long powering(int x, int y) {
    if (y == 1)
        return x;
    if (y % 2 == 1)
        return x*powering(x, y-1) % MOD;
    long long p = powering(x, y/2);
    return p*p % MOD;
}

int main() {
    fastIO;

    int N, R;
    cin >> N >> R;

    long long num = 1, deno = 1;
    for (int i = 0; i < R; i++) {
        num *= (N-i);
        num %= MOD;
        deno *= (R-i);
        deno %= MOD;
    }
    deno = powering(deno, MOD-2);
    cout << num*deno % MOD;

    return 0;
}