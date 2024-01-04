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

int w[101][101][101];
int solution(int a, int b, int c);

signed main()
{
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                w[i][j][k] = INT32_MAX;

    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a, b, c) << '\n';
    }

    return 0;
}

int solution(int a, int b, int c) {
    if (w[a+50][b+50][c+50] != INT32_MAX) return w[a+50][b+50][c+50];

    if (a <= 0 || b <= 0 || c <= 0) {
        w[a+50][b+50][c+50] = 1;
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        w[a+50][b+50][c+50] = solution(20, 20, 20);
        return w[a+50][b+50][c+50];
    }
    if (a < b && b < c) {
        w[a+50][b+50][c+49] = solution(a, b, c-1);
        w[a+50][b+49][c+49] = solution(a, b-1, c-1);
        w[a+50][b+49][c+50] = solution(a, b-1, c);
        return w[a+50][b+50][c+49] + w[a+50][b+49][c+49] - w[a+50][b+49][c+50];
    }

    w[a+49][b+50][c+50] = solution(a-1, b, c);
    w[a+49][b+49][c+50] = solution(a-1, b-1, c);
    w[a+49][b+50][c+49] = solution(a-1, b, c-1);
    w[a+49][b+49][c+49] = solution(a-1, b-1, c-1);
    return w[a+49][b+50][c+50] + w[a+49][b+49][c+50] + w[a+49][b+50][c+49] - w[a+49][b+49][c+49];
}