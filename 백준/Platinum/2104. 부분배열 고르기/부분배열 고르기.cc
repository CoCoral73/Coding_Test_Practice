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
    int sum;
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
    vector<int> arr;
    Node** segTree;
    int MIN_idx;
    int MIN_sum;
    int MAX = 0;
public:
    BJ();
    void initTree(int now);
    void getSubValue(int now, int S, int E);
    void solution(int now, int S, int E);
};

BJ::BJ() {
    cin >> N;
    arr = vector<int>(N);
    for (int &a : arr)
        cin >> a;
    segTree = new Node*[4*N];
    segTree[1] = createNode(0, N-1);
    initTree(1);
    MIN_sum = segTree[1]->sum;
    solution(segTree[1]->MIN, 0, N-1);
    cout << MAX;
}
void BJ::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->sum = arr[s];
        segTree[now]->MIN = s;
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    if (arr[segTree[2*now]->MIN] <= arr[segTree[2*now+1]->MIN])
        segTree[now]->MIN = segTree[2*now]->MIN;
    else
        segTree[now]->MIN = segTree[2*now+1]->MIN;
    segTree[now]->sum = segTree[2*now]->sum + segTree[2*now+1]->sum;
}

void BJ::getSubValue(int now, int S, int E) {
    if (S > E)
        return;
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        if (arr[MIN_idx] > arr[segTree[now]->MIN])
            MIN_idx = segTree[now]->MIN;
        MIN_sum += segTree[now]->sum;
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
    MAX = max(MAX, arr[now]*MIN_sum);

    MIN_idx = now-1; MIN_sum = 0;
    getSubValue(1, S, now-1);
    solution(MIN_idx, S, now-1);

    MIN_idx = now+1; MIN_sum = 0;
    getSubValue(1, now+1, E);
    solution(MIN_idx, now+1, E);
}

signed main() {
    fastIO;

    BJ Q2104;
}