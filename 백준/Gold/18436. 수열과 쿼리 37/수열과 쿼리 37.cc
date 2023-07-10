#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef struct node {
    int s, e;
    int odd, even;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    return newNode;
}

class Q1275 {
    int N, M;
    vector<long long> num;
    Node** segTree;
    long long result;
public:
    Q1275();
    void initTree(int now);
    void processOrder();
    void changeNum(int now, int index, long long n);
    void getSubSum(int now, int S, int E, int flag);
};

Q1275::Q1275() {
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
void Q1275::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->odd = 0;
        segTree[now]->even = 0;
        if (num[s] % 2 == 0)
            segTree[now]->even = 1;
        else
            segTree[now]->odd = 1;
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->odd = segTree[2*now]->odd + segTree[2*now+1]->odd;
    segTree[now]->even = segTree[2*now]->even + segTree[2*now+1]->even;
}
void Q1275::processOrder() {
    long long a, b, c;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            changeNum(1, b-1, c);
        else if (a == 2) {
            result = 0;
            getSubSum(1, b-1, c-1, 0);
            cout << result << '\n';
        }
        else {
            result = 0;
            getSubSum(1, b-1, c-1, 1);
            cout << result << '\n';
        }
    }
}
void Q1275::changeNum(int now, int index, long long n) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        if (n % 2 == 0) {
            segTree[now]->even = 1;
            segTree[now]->odd = 0;
        }
        else {
            segTree[now]->even = 0;
            segTree[now]->odd = 1;
        }
        return;
    }
    if (index <= m)
        changeNum(2 * now, index, n);
    else if (m+1 <= index)
        changeNum(2*now+1, index, n);
    segTree[now]->odd = segTree[2*now]->odd + segTree[2*now+1]->odd;
    segTree[now]->even = segTree[2*now]->even + segTree[2*now+1]->even;
}
void Q1275::getSubSum(int now, int S, int E, int flag) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        if (flag == 0)
            result += segTree[now]->even;
        else
            result += segTree[now]->odd;
        return;
    }
    if (S <= m && m+1 <= E) {
        getSubSum(2*now, S, m, flag);
        getSubSum(2*now+1, m+1, E, flag);
    }
    else if (E <= m) {
        getSubSum(2 * now, S, E, flag);
    }
    else if (m+1 <= S) {
        getSubSum(2 * now + 1, S, E, flag);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Q1275 a;
    a.processOrder();
}