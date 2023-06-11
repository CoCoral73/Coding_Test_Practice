#include <iostream>
#include <vector>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a%b);
}

int main() {
    int N, first, ring;

    cin >> N;
    cin >> first;
    for (int i = 0; i < N-1; i++) {
        cin >> ring;
        int gcd;
        if (first > ring) {
            gcd = GCD(first, ring);
            cout << first/gcd << '/' << ring/gcd << '\n';
        }
        else {
            gcd = GCD(ring, first);
            cout << first/gcd << '/' << ring/gcd << '\n';
        }
    }
}