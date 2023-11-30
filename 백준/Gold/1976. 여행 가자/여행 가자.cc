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
#include <cctype>
#include <memory.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, M;
    int parent[201];
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> N >> M;

    int tmp;
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            if (tmp == 1)
                unionParent(i, j);
        }
    }

    vector<int> city;
    int MIN = N;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        city.emplace_back(tmp);
        MIN = min(MIN, tmp);
    }

    for (int i = 0; i < M; i++) {
        if (findParent(city[i]) != MIN) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}
int BJ::findParent(int x) {
    if (parent[x] == x)
        return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
}
void BJ::unionParent(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);
    if (px <= py)
        parent[py] = px;
    else
        parent[px] = py;
}

signed main(){
    fastIO;

    BJ a;
}
