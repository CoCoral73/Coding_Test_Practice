#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
    int s, e;
    long long sum;
    struct node* left;
    struct node* right;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

class Q2042 {
    int N, M, K;
    vector<long long> num;
    Node* root;
    long long result;
public:
    Q2042();
    void initTree(Node* p);
    void processOrder();
    void changeNum(Node* p, int index, long long n);
    void getSubSum(Node* p, int S, int E);
};

Q2042::Q2042() {
    cin >> N >> M >> K;
    long long n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        num.emplace_back(n);
    }
    root = createNode(0, N-1);
    initTree(root);
}
void Q2042::initTree(Node *p) {
    int s = p->s, e = p->e, m = (s+e)/2;
    if (s == e) {
        p->sum = num[s];
        return;
    }
    p->left = createNode(s, m);
    p->right = createNode(m+1, e);
    initTree(p->left);
    initTree(p->right);
    p->sum = p->left->sum + p->right->sum;
}
void Q2042::processOrder() {
    long long a, b, c;
    for (int i = 0; i < M+K; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            changeNum(root, b-1, c);
        else {
            result = 0;
            getSubSum(root, b - 1, c - 1);
            cout << result << '\n';
        }
    }
}
void Q2042::changeNum(Node *p, int index, long long n) {
    int s = p->s, e = p->e, m = (s+e)/2;
    if (s == e) {
        p->sum = n;
        return;
    }
    if (s <= index && index <= m) {
        changeNum(p->left, index, n);
        p->sum = p->left->sum + p->right->sum;
    }
    else {
        changeNum(p->right, index, n);
        p->sum = p->left->sum + p->right->sum;
    }
}
void Q2042::getSubSum(Node *p, int S, int E) {
    int s = p->s, e = p->e, m = (s+e)/2;
    if (s == S && e == E) {
        result += p->sum;
        return;
    }
    if (S <= m && m+1 <= E) {
        getSubSum(p->left, S, m);
        getSubSum(p->right, m+1, E);
    }
    else if (E <= m)
        getSubSum(p->left, S, E);
    else if (m+1 <= S)
        getSubSum(p->right, S, E);
}

int main() {
    Q2042 a;
    a.processOrder();
}