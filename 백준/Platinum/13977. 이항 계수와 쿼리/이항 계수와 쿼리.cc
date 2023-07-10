#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const long long MOD = 1000000007;

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

    int M, N, K;
    cin >> M;

    vector<long long> fac = {1, 1};
    for (int i = 2; i < 4000001; i++)
        fac.emplace_back(i*fac[i-1] % MOD);

    for (int i = 0; i < M; i++) {
        cin >> N >> K;
        K = min(K, N-K);
        long long num = fac[N];
        long long deno1 = fac[K];
        deno1 = squaring(deno1, MOD-2);
        long long deno2 = fac[N-K];
        deno2 = squaring(deno2, MOD-2);
        long long answer = num*deno1 % MOD;
        answer = answer*deno2 % MOD;
        cout << answer << '\n';
    }
}