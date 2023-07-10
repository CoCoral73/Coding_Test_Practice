#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
    int s, e;
    long long multi;
    //long long update;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    //newNode->update = 0;
    return newNode;
}

class Q11505 {
    int N, M, K;
    vector<long long> num;
    Node** segTree;
    int last = 0;
    long long result;
public:
    Q11505();
    void initTree(int now);
    void processOrder();
    void changeNum(int now, int S, long long n);
    void getSubMulti(int now, int S, int E);
    void propagate(int now);
};

Q11505::Q11505() {
    cin >> N >> M >> K;
    long long n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        num.emplace_back(n);
    }
    segTree = new Node*[3*N+2];
    segTree[1] = createNode(0, N-1);
    initTree(1);
}
void Q11505::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    last = max(last, now);
    if (s == e) {
        segTree[now]->multi = num[s];
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->multi = (segTree[2*now]->multi * segTree[2*now+1]->multi) % 1000000007;
}
void Q11505::processOrder() {
    long long a, b, c;
    for (int i = 0; i < M+K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            changeNum(1, b-1, c);
        }
        else {
            result = 1;
            getSubMulti(1, b-1, c-1);
            cout << result << '\n';
        }
    }
}
void Q11505::changeNum(int now, int index, long long n) {
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
void Q11505::getSubMulti(int now, int S, int E) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        result = (result * segTree[now]->multi) % 1000000007;
        return;
    }
    if (S <= m && m+1 <= E) {
        getSubMulti(2*now, S, m);
        getSubMulti(2*now+1, m+1, E);
    }
    else if (E <= m) {
        getSubMulti(2 * now, S, E);
    }
    else if (m+1 <= S) {
        getSubMulti(2 * now + 1, S, E);
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
    Q11505 a;
    a.processOrder();
}