#include <iostream>
using namespace std;

long long **M;
long long rst = 0;
long long** matrix_multiplication(long long** A, long long** B) {
    long long** result = new long long*[2];
    if (!B) {
        for (int i = 0; i < 2; i++) {
            result[i] = new long long[2];
            for (int j = 0; j < 2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    result[i][j] += A[i][k] * A[k][j];
                result[i][j] %= 1000000000;
            }
        }
    }
    else {
        for (int i = 0; i < 2; i++) {
            result[i] = new long long[2];
            for (int j = 0; j < 2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= 1000000000;
            }
        }
    }
    return result;
}
long long** solve(long long b) {
    if (b == 1)
        return M;
    long long** result;
    if (b % 2 == 0) {
        result = solve(b/2);
        result = matrix_multiplication(result, nullptr);
        return result;
    }
    else {
        result = solve(b/2);
        result = matrix_multiplication(result, nullptr);
        result = matrix_multiplication(result, M);
        return result;
    }
}
int main() {
    long long **result;
    M = new long long*[2];
    result = new long long*[2];
    for (int i = 0; i < 2; i++) {
        M[i] = new long long[2];
        result[i] = new long long[2];
    }
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;

    long long a, b;
    cin >> a >> b;
    result = solve(a);
    rst -= result[0][0];
    result = solve(b+1);
    rst += result[0][0];
    cout << (rst+1000000000)%1000000000;
}

/*
 * 1 1 2 3 5 8 13 21 34 55 89 144
 * 7항까지 합: 33 = 9항-1
 * 8항까지 합: 54 = 10항-1
 * a~b항 합: b+2항 - a+1항
 */