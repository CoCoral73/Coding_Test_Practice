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

typedef struct node {
    int x, y;
    int R;
    node(int x, int y, int R) {
        this->x = x;
        this->y = y;
        this->R = R;
    }
}NODE;

class BJ {
    int T;
    int N;
    int parent[3000];
    vector<NODE> location;
public:
    BJ();
    int findParent(int x);
    void unionParent(int x, int y);
};

BJ::BJ() {
    cin >> T;
    int x, y, R;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> R;
            location.emplace_back(x, y, R);
            parent[i] = i;
        }

        int answer = N;
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                NODE c1 = location[i], c2 = location[j];
                int o1o2 = pow((double)(c2.x - c1.x), 2) + pow((double)(c2.y-c1.y), 2);
                int r1r2 = pow((double)(c1.R + c2.R),2);
                if (o1o2 <= r1r2 && findParent(i) != findParent(j)) {
                    unionParent(i, j);
                    answer--;
                }
            }
        }
        cout << answer << '\n';
        location.clear();
    }
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
        parent[py] = parent[px];
    else
        parent[px] = parent[py];
}

signed main(){
    fastIO;

    BJ Q10216;
}
