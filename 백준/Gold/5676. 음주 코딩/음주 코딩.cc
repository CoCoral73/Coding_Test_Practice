#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
    int s, e;
    int multi;
}Node;
node* createNode(int s, int e) {
    Node* newNode = new Node;
    newNode->s = s;
    newNode->e = e;
    return newNode;
}

class Q11505 {
    vector<long long> num;
    Node** segTree;
    int result;
public:
    Q11505();
    void initTree(int now);
    void processOrder();
    void changeNum(int now, int index, int n);
    void getSubMulti(int now, int S, int E);
};

Q11505::Q11505() {}
void Q11505::processOrder() {
    int N, K, x, y;
    char order;
    while (true) {
        cin >> N >> K;
        if (cin.eof())
            break;
        num.clear();
        for (int i = 0; i < N; i++) {
            cin >> x;
            if (x > 0)
                x = 1;
            else if (x < 0)
                x = -1;
            num.emplace_back(x);
        }
        segTree = new Node*[4*N];
        segTree[1] = createNode(0, N-1);
        initTree(1);
        for (int i = 0; i < K; i++) {
            cin >> order >> x >> y;
            if (order == 'C')
                changeNum(1, x-1, y);
            else {
                result = 1;
                getSubMulti(1, x-1, y-1);
                if (result > 0)
                    cout << '+';
                else if (result < 0)
                    cout << '-';
                else
                    cout << 0;
            }
        }
        cout << '\n';
        delete[] segTree;
    }
}
void Q11505::initTree(int now) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        segTree[now]->multi = num[s];
        return;
    }
    segTree[2*now] = createNode(s, m);
    segTree[2*now+1] = createNode(m+1, e);
    initTree(2*now);
    initTree(2*now+1);
    segTree[now]->multi = segTree[2*now]->multi * segTree[2*now+1]->multi;
}

void Q11505::changeNum(int now, int index, int n) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == e) {
        if (n > 0)
            n = 1;
        else if (n < 0)
            n = -1;
        segTree[now]->multi = n;
        return;
    }
    if (index <= m)
        changeNum(2 * now, index, n);
    else if (m+1 <= index)
        changeNum(2*now+1, index, n);
    segTree[now]->multi = segTree[2 * now]->multi * segTree[2 * now + 1]->multi;
}
void Q11505::getSubMulti(int now, int S, int E) {
    int s = segTree[now]->s, e = segTree[now]->e, m = (s+e)/2;
    if (s == S && e == E) {
        result *= segTree[now]->multi;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Q11505 a;
    a.processOrder();
}