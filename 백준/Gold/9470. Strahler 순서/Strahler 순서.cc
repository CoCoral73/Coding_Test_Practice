#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node {
    int MAX_order;
    int MAX_cnt;
    int before;
    vector<int> next;
}NODE;
NODE createNode() {
    NODE newNode;
    newNode.MAX_order = 0;
    newNode.MAX_cnt = 0;
    newNode.before = 0;
    return newNode;
}

int main() {
    int T, K, M, P, A, B;
    pair<int, int> *result;

    cin >> T;
    result = new pair<int, int>[T];
    for (int i = 0; i < T; i++) {
        cin >> K >> M >> P;
        NODE* river = new NODE[M+1];
        for (int j = 1; j <= M; j++)
            river[j] = createNode();

        for (int j = 0; j < P; j++) {
            cin >> A >> B;
            river[A].next.emplace_back(B);
            river[B].before++;
        }

        queue<int> Q;
        for (int j = 1; j <= M; j++) {
            if (river[j].before == 0) {
                river[j].MAX_order = 1;
                river[j].MAX_cnt = 1;
                Q.emplace(j);
            }
        }

        while (!Q.empty()) {
            int front = Q.front();
            Q.pop();
            for (int j = 0; j < river[front].next.size(); j++) {
                int next = river[front].next[j];
                river[next].before--;
                if (river[next].before == 0)
                    Q.emplace(next);
                if (river[front].MAX_order > river[next].MAX_order) {
                    river[next].MAX_order = river[front].MAX_order;
                    river[next].MAX_cnt = 1;
                }
                else if (river[front].MAX_order == river[next].MAX_order && river[next].MAX_cnt == 1) {
                    river[next].MAX_order += 1;
                    river[next].MAX_cnt++;
                }
            }
        }
        result[i] = {K, river[M].MAX_order};
    }

    for (int i = 0; i < T; i++)
        cout << result[i].first << ' ' << result[i].second << '\n';
}