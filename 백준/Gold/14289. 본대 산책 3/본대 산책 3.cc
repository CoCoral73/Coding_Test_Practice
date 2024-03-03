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
    int n, m;
    int D;
    int **adj;
public:
    BJ();
    int** powering(int **x, int y);
    int** matrix_multiplication(int N, int **A, int **B);
};

BJ::BJ() {
    cin >> n >> m;
    adj = new int *[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1][b-1] = 1;
        adj[b-1][a-1] = 1;
    }

    cin >> D;
    cout << powering(adj, D)[0][0];
}
int** BJ::powering(int **x, int y) {
    if (y == 1)
        return x;
    if (y % 2 == 1) {
        int **p = powering(x, y/2);
        int **q = matrix_multiplication(n, p, p);
        return matrix_multiplication(n, q, x);
    }
    int **p = powering(x, y/2);
    return matrix_multiplication(n, p, p);
}
int** BJ::matrix_multiplication(int N, int **A, int **B) {
    int** result = new int*[N];
    for (int i = 0; i < N; i++) {
        result[i] = new int[N];
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++)
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % 1000000007;
            //result[i][j] %= 1000000007;
        }
    }
    return result;
}

signed main() {
    fastIO;

    BJ Q14289;
}