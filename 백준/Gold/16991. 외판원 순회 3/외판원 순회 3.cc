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
    vector<pair<double, double>> location;
    double **visited;
    int power[16] = {1};
public:
    BJ();
    void dfs(int route, int now);
    double calculate(int i, int j) {
        return sqrt(pow(location[i].first-location[j].first, 2)+pow(location[i].second-location[j].second, 2));
    }
};

BJ::BJ() {
    cin >> N;
    double x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        location.emplace_back(x, y);
        if (i > 0)
            power[i] = power[i-1]*2;
    }

    visited = new double *[1 << N];
    for (int i = 0; i < (1 << N); i++) {
        visited[i] = new double[N];
        for (int j = 0; j < N; j++)
            visited[i][j] = INT32_MAX;
    }

    dfs(1, 0);
    printf("%lf", visited[1][0]);

    for (int i = 0; i < (1 << N); i++)
        delete visited[i];
    delete []visited;
}
void BJ::dfs(int route, int now) {
    if (route == (1 << N) - 1) {
        visited[route][now] = calculate(now, 0);
        return;
    }
    if (visited[route][now] != INT32_MAX)
        return;

    for (int i = 1; i < N; i++) {
        int binary = power[i];
        if (route & binary) continue;
        if (visited[route|binary][i] == INT32_MAX)
            dfs(route | binary, i);
        if (visited[route | binary][i] != INT32_MAX)
            visited[route][now] = min(visited[route][now], visited[route | binary][i] + calculate(now, i));
    }
}

signed main() {
    BJ Q16991;
}
