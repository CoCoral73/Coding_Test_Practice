#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct node {
    int s, e;
    int MIN;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    return newNode;
}

class BJ {
    int N;
    vector<int> histogram;
    Node** segTree;
    int MIN_idx;
    int MAX;
public:
    BJ();
    void initTree(int now);
    void getSubValue(int now, int S, int E);
    void solution(int now, int S, int E);
};

BJ::BJ() {
    while (true) {
        cin >> N;
        if (N == 0)
            break;
        histogram = vector<int>(N);
        for (int &h: histogram)
            cin >> h;
        segTree = new Node *[4 * N];
        segTree[1] = createNode(0, N - 1);
        initTree(1);
        MAX = 0;
        solution(segTree[1]->MIN, 0, N - 1);
        cout << MAX << endl;
        delete []segTree;
    }
}
void BJ::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->MIN = s;
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    if (histogram[segTree[2*now]->MIN] <= histogram[segTree[2*now+1]->MIN])
        segTree[now]->MIN = segTree[2*now]->MIN;
    else
        segTree[now]->MIN = segTree[2*now+1]->MIN;
}

void BJ::getSubValue(int now, int S, int E) {
    if (S > E)
        return;
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        if (histogram[MIN_idx] > histogram[segTree[now]->MIN])
            MIN_idx = segTree[now]->MIN;
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
void BJ::solution(int now, int S, int E) {
    if (S > E)
        return ;
    MAX = max(MAX, histogram[now]*(E-S+1));

    MIN_idx = now-1;
    getSubValue(1, S, now-1);
    solution(MIN_idx, S, now-1);

    MIN_idx = now+1;
    getSubValue(1, now+1, E);
    solution(MIN_idx, now+1, E);
}

signed main() {
    fastIO;

    BJ Q1725;
}