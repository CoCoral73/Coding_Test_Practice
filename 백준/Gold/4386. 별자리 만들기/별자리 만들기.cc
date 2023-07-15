#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct star {
    int n;
    double x, y;
    struct star *parent;
}STAR;
STAR* createStar(int n, double x, double y) {
    STAR* s = new STAR;
    s->n = n;
    s->x = x;
    s->y = y;
    s->parent = s;
    return s;
}
int findParent(STAR** stars, STAR* s) {
    if (s == s->parent)
        return s->n;
    int p = findParent(stars, s->parent);
    s->parent = stars[p];
    return p;
}
typedef struct edge {
    int star1, star2;
    double cost;
    bool operator<(const edge e) const {
        return this->cost < e.cost;
    }
}EDGE;

double calculate(STAR* s1, STAR* s2) {
    double answer = 0;
    answer += pow(abs(s2->x-s1->x), 2);
    answer += pow(abs(s2->y-s1->y), 2);
    return sqrt(answer);
}

int main() {
    fastIO;

    int n;
    double x, y;

    cin >> n;
    STAR** stars = new STAR*[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        stars[i] = createStar(i, x, y);
    }

    vector<EDGE> edge;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++)
            edge.push_back({i, j, calculate(stars[i], stars[j])});
    }
    sort(edge.begin(), edge.end());

    double answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        EDGE e = edge[i];
        int P_s1 = findParent(stars, stars[e.star1]);
        int P_s2 = findParent(stars, stars[e.star2]);
        if (P_s1 != P_s2) {
            answer += e.cost;
            if (P_s1 <= P_s2)
                stars[P_s2]->parent = stars[P_s1];
            else
                stars[P_s1]->parent = stars[P_s2];
        }
    }
    printf("%.2lf", answer);
}