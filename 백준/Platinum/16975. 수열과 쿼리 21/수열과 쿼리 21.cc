#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
    int s, e;
    long long A;
    long long update;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    newNode->update = 0;
    return newNode;
}

class Q2042 {
    int N, M;
    vector<long long> num;
    Node** segTree;
    long long result;
public:
    Q2042();
    void initTree(int now);
    void processOrder();
    void changeNum(int now, int S, int E, long long n);
    void getSubSum(int now, int S);
    void propagate(int now);
};

Q2042::Q2042() {
    cin >> N;
    long long n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        num.emplace_back(n);
    }
    segTree = new Node*[4*N];
    segTree[1] = createNode(0, N-1);
    initTree(1);
}
void Q2042::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->A = num[s];
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->A = segTree[2*now]->A + segTree[2*now+1]->A;
}
void Q2042::processOrder() {
    long long a, b, c, d;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> d;
            changeNum(1, b-1, c-1, d);
        }
        else {
            result = 0;
            getSubSum(1, b-1);
            cout << result << '\n';
        }
    }
}
void Q2042::changeNum(int now, int S, int E, long long n) {
    propagate(now);
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        segTree[now]->A += (e-s+1)*n;
        if (s != e) {
            segTree[2 * now]->update += n;
            segTree[2 * now + 1]->update += n;
        }
        return;
    }
    if (S <= m && m+1 <= E) {
        changeNum(2*now, S, m, n);
        changeNum(2*now+1, m+1, E, n);
    }
    else if (E <= m) {
        changeNum(2*now, S, E, n);
        changeNum(2*now+1, m+1, segTree[2*now+1]->e, 0);
    }
    else if (m+1 <= S) {
        changeNum(2*now, segTree[2*now]->s, m, 0);
        changeNum(2*now+1, S, E, n);
    }
    segTree[now]->A = segTree[2*now]->A + segTree[2*now+1]->A;
}
void Q2042::getSubSum(int now, int S) {
    propagate(now);
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        result += segTree[now]->A;
        return;
    }
    if (S <= m) {
        getSubSum(2*now, S);
        //getSubSum(2*now+1, m+1, E);
    }
    else if (m+1 <= S) {
        getSubSum(2 * now + 1, S);
    }
}
void Q2042::propagate(int now) {
    int s = segTree[now]->s, e = segTree[now]->e;
    segTree[now]->A += (e - s + 1)*segTree[now]->update;
    if (s != e) {
        segTree[2*now]->update += segTree[now]->update;
        segTree[2*now+1]->update += segTree[now]->update;
    }
    segTree[now]->update = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Q2042 a;
    a.processOrder();
}