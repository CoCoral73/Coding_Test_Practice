#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N;
    int grid[16][16];
    int **visited;
    int power[16];
public:
    BJ();
    void dfs(int route, int now);
};

BJ::BJ() {
    cin >> N;
    power[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
        if (i > 0)
            power[i] = power[i-1]*2;
    }

    visited = new int *[1 << N];
    for (int i = 0; i < (1 << N); i++) {
        visited[i] = new int[N];
        for (int j = 0; j < N; j++)
            visited[i][j] = INT32_MAX;
    }

    dfs(1, 0);
    cout << visited[1][0];

    for (int i = 0; i < (1 << N); i++)
        delete visited[i];
    delete []visited;
}
void BJ::dfs(int route, int now) {
    if (route == (1 << N) - 1) {
        visited[route][now] = grid[now][0];
        return;
    }
    if (visited[route][now] != INT32_MAX)
        return;

    for (int i = 1; i < N; i++) {
        int binary = power[i];
        if (route & binary) continue;
        if (grid[now][i] == 0) continue;
        if (visited[route|binary][i] == INT32_MAX)
            dfs(route | binary, i);
        if (visited[route | binary][i] != 0)
            visited[route][now] = min(visited[route][now], visited[route | binary][i] + grid[now][i]);
    }

    if (visited[route][now] == INT32_MAX)
        visited[route][now] = 0;
}

signed main() {
    fastIO;

    BJ Q2098;
}
