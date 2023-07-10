#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
    int s, e;
    long long sum;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    return newNode;
}

class Q1275 {
    int N, Q;
    vector<long long> num;
    Node** segTree;
    long long result;
public:
    Q1275();
    void initTree(int now);
    void processOrder();
    void changeNum(int now, int S, long long n);
    void getSubSum(int now, int S, int E);
};

Q1275::Q1275() {
    cin >> N >> Q;
    long long n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        num.emplace_back(n);
    }
    segTree = new Node*[3*N+2];
    segTree[1] = createNode(0, N-1);
    initTree(1);
}
void Q1275::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->sum = num[s];
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->sum = segTree[2*now]->sum + segTree[2*now+1]->sum;
}
void Q1275::processOrder() {
    long long a, b, x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y >> a >> b;
        result = 0;
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        getSubSum(1, x-1, y-1);
        cout << result << '\n';
        changeNum(1, a-1, b);
    }
}
void Q1275::changeNum(int now, int index, long long n) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->sum = n;
        return;
    }
    if (index <= m)
        changeNum(2 * now, index, n);
    else if (m+1 <= index)
        changeNum(2*now+1, index, n);
    segTree[now]->sum = segTree[2 * now]->sum + segTree[2 * now + 1]->sum;
}
void Q1275::getSubSum(int now, int S, int E) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        result += segTree[now]->sum;
        return;
    }
    if (S <= m && m+1 <= E) {
        getSubSum(2*now, S, m);
        getSubSum(2*now+1, m+1, E);
    }
    else if (E <= m) {
        getSubSum(2 * now, S, E);
    }
    else if (m+1 <= S) {
        getSubSum(2 * now + 1, S, E);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Q1275 a;
    a.processOrder();
}