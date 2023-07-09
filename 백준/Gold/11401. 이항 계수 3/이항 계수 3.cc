#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

long long MOD = 1000000007;

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a%b);
}
long long squaring(long long x, long long y) {
    if (y == 1)
        return x;
    if (y % 2 == 0) {
        long long s = squaring(x, y/2);
        return s*s % MOD;
    }
    else {
        long long s = squaring(x, y-1);
        return (s*x) % MOD;
    }
}


int main() {
    fastIO;

    int N, K;

    cin >> N >> K;
    K = min(K, N-K);

    long long num = 1;
    long long deno = 1;
    for (int i = 0; i < K; i++) {
        int a = N-i;
        int b = K-i;
        num *= a;
        num %= MOD;
        deno *= b;
        deno %= MOD;
    }
    deno = squaring(deno, MOD-2);
    long long answer = num*deno % MOD;
    cout << answer;
}