#include <iostream>
using namespace std;

long long** M;
long long** matrix_multiplication(long long N, long long** A, long long** B) {
    long long** result = new long long*[N];
    if (!B) {
        for (int i = 0; i < N; i++) {
            result[i] = new long long[N];
            for (int j = 0; j < N; j++) {
                result[i][j] = 0;
                for (int k = 0; k < N; k++)
                    result[i][j] += A[i][k] * A[k][j];
                result[i][j] %= 1000000007;
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            result[i] = new long long[N];
            for (int j = 0; j < N; j++) {
                result[i][j] = 0;
                for (int k = 0; k < N; k++)
                    result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= 1000000007;
            }
        }
    }
    return result;
}

long long** solve(long long n) {
    if (n == 1)
        return M;
    long long** result = new long long*[2];
    for (int i = 0; i < 2; i++)
        result[i] = new long long[2];

    if (n % 2 == 0) {
        result = solve(n/2);
        return matrix_multiplication(2, result, nullptr);
    }
    else {
        result = solve(n/2);
        result = matrix_multiplication(2, result, nullptr);
        return matrix_multiplication(2, result, M);
    }
}
long long gcd(long long n, long long m) {
    if (m == 0)
        return n;
    else
        return gcd(m, n%m);
}

int main() {
    M = new long long*[2];
    for (int i = 0; i < 2; i++)
        M[i] = new long long[2];
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;

    long long tc, n, m, GCD;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n >> m;
        GCD = gcd(n, m);
        cout << solve(GCD)[0][1] << '\n';
    }
}