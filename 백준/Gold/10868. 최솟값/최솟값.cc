#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef struct node {
    int s, e;
    long long MIN, MAX;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    return newNode;
}

class Q2357 {
    int N, M;
    vector<long long> num;
    Node** segTree;
    long long MIN, MAX;
public:
    Q2357();
    void initTree(int now);
    void processOrder();
    //void changeNum(int now, int S, long long n);
    void getSubValue(int now, int S, int E);
    void propagate(int now);
};

Q2357::Q2357() {
    cin >> N >> M;
    long long n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        num.emplace_back(n);
    }
    segTree = new Node*[3*N+2];
    segTree[1] = createNode(0, N-1);
    initTree(1);
}
void Q2357::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->MIN = num[s];
        segTree[now]->MAX = num[s];
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->MIN = min(segTree[2*now]->MIN, segTree[2*now+1]->MIN);
    segTree[now]->MAX = max(segTree[2*now]->MAX, segTree[2*now+1]->MAX);
}
void Q2357::processOrder() {
    long long a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        MIN = LONG_LONG_MAX;
        MAX = LONG_LONG_MIN;
        getSubValue(1, a-1, b-1);
        cout << MIN << '\n';
    }
}
/*
void Q2357::changeNum(int now, int index, long long n) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->multi = n;
        return;
    }
    if (index <= m)
        changeNum(2 * now, index, n);
    else if (m+1 <= index)
        changeNum(2*now+1, index, n);
    segTree[now]->multi = (segTree[2 * now]->multi * segTree[2 * now + 1]->multi) % 1000000007;
}
*/
void Q2357::getSubValue(int now, int S, int E) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        MIN = min(MIN, segTree[now]->MIN);
        MAX = max(MAX, segTree[now]->MAX);
        return;
    }
    if (S <= m && m+1 <= E) {
        getSubValue(2*now, S, m);
        getSubValue(2*now+1, m+1, E);
    }
    else if (E <= m) {
        getSubValue(2 * now, S, E);
    }
    else if (m+1 <= S) {
        getSubValue(2 * now + 1, S, E);
    }
}
/*
void Q11505::propagate(int now) {
    int s = segTree[now]->s, e = segTree[now]->e;
    segTree[now]->sum += (e - s + 1)*segTree[now]->update;
    if (s != e) {
        segTree[2*now]->update += segTree[now]->update;
        segTree[2*now+1]->update += segTree[now]->update;
    }
    segTree[now]->update = 0;
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Q2357 a;
    a.processOrder();
}