#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

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
        return s*s % 1000000007;
    }
    else {
        long long s = squaring(x, y-1);
        return (s*x) % 1000000007;
    }
}
long long convert(long long a, long long b) {
    long long _b = squaring(b, 1000000005);
    return (a*_b)%1000000007;
}

int main() {
    fastIO;

    int M;
    long long a, b, answer = 0;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b >> a;
        long long gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
        answer += convert(a, b);
        answer %= 1000000007;
    }
    cout << answer;
}