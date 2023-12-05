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
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int G, P;
    int *parent;
    int answer = 0;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> G >> P;
    parent = new int[G+1];
    for (int i = 0; i <= G; i++)
        parent[i] = i;

    int g;
    for (int i = 0; i < P; i++) {
        cin >> g;
        int p = findParent(g);
        if (p == 0) break;
        answer++;
        unionParent(p-1, p);
    }
    cout << answer;
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

    BJ Q10775;
}
