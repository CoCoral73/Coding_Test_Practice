#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef struct node {
    int s, e;
    long long balance;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    return newNode;
}

class BJ {
    int N, Q;
    Node** segTree;
    long long answer;
public:
    BJ();
    void initTree(int now);
    void processOrder();
    void changeNum(int now, int index, long long n);
    void getSubVariance(int now, int S, int E);
};

BJ::BJ() {
    cin >> N >> Q;
    segTree = new Node*[4*N];
    segTree[1] = createNode(1, N);
    initTree(1);
}
void BJ::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->balance = 0;
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->balance = 0;
}
void BJ::processOrder() {
    long long a, b, c;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            changeNum(1, b, c);
        else {
            answer = 0;
            getSubVariance(1, b, c);
            cout << answer << '\n';
        }
    }
}
void BJ::changeNum(int now, int index, long long n) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->balance += n;
        return;
    }
    if (index <= m)
        changeNum(2 * now, index, n);
    else if (m+1 <= index)
        changeNum(2*now+1, index, n);
    segTree[now]->balance = segTree[2 * now]->balance + segTree[2 * now + 1]->balance;
}
void BJ::getSubVariance(int now, int S, int E) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        answer += segTree[now]->balance;
        return;
    }
    if (S <= m && m+1 <= E) {
        getSubVariance(2*now, S, m);
        getSubVariance(2*now+1, m+1, E);
    }
    else if (E <= m) {
        getSubVariance(2 * now, S, E);
    }
    else if (m+1 <= S) {
        getSubVariance(2 * now + 1, S, E);
    }
}

int main() {
    fastIO;
    BJ a;
    a.processOrder();
}