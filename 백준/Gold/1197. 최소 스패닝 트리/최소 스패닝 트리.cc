#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct vertex {
    int num;
    struct vertex *parent;
}VERTEX;
VERTEX* createVertex(int n) {
    VERTEX* v = new VERTEX;
    v->num = n;
    v->parent = v;
    return v;
}
int findParent(VERTEX** vs, VERTEX* v) {
    if (v == v->parent)
        return v->num;
    int p = findParent(vs, v->parent);
    v->parent = vs[p];
    return p;
}

typedef struct edge {
    int weight;
    int V1, V2;
    bool operator<(const edge v) const {
        return this->weight > v.weight;
    }
}EDGE;

int main() {
    fastIO;

    int V, E;
    cin >> V >> E;

    VERTEX** Vs = new VERTEX*[V+1];
    for (int i = 1; i <= V; i++)
        Vs[i] = createVertex(i);

    priority_queue<EDGE> Q;
    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        Q.push({C, A, B});
    }
    
    long long answer = 0;
    while (!Q.empty()) {
        EDGE e = Q.top();
        Q.pop();
        int P_V1 = findParent(Vs, Vs[e.V1]);
        int P_V2 = findParent(Vs, Vs[e.V2]);
        if (P_V1 != P_V2) {
            answer += e.weight;
            if (P_V1 < P_V2)
                Vs[P_V2]->parent = Vs[P_V1];
            else
                Vs[P_V1]->parent = Vs[P_V2];
        }
    }
    cout << answer;
}