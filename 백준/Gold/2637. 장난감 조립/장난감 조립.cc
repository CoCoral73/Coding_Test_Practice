#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node {
    int answer;
    int before;
    vector<pair<int, int>> next;
}NODE;
NODE createNode() {
    NODE newNode;
    newNode.answer = 0;
    newNode.before = 0;
    return newNode;
}

int main() {
    int N, M, X, Y, K;
    NODE* ts;

     cin >> N;
     ts = new NODE[N+1];
     for (int i = 1; i <= N; i++)
         ts[i] = createNode();
     ts[N].answer = 1;

     cin >> M;
     for (int i = 0; i < M; i++) {
         cin >> X >> Y >> K;
         ts[X].next.emplace_back(Y, K);
         ts[Y].before++;
     }

     queue<int> Q;
     Q.emplace(N);
     int next, count;
     while (!Q.empty()) {
         int front = Q.front();
         Q.pop();
         for (int i = 0; i < ts[front].next.size(); i++) {
             tie(next, count) = ts[front].next[i];
             ts[next].before--;
             ts[next].answer += ts[front].answer*count;
             if (ts[next].before == 0)
                 Q.emplace(next);
         }
     }

     for (int i = 1; i <= N; i++) {
         if (ts[i].next.size() == 0)
             cout << i << ' ' << ts[i].answer << '\n';
     }
}