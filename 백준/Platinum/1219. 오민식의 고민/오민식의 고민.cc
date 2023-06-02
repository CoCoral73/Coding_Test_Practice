#include <iostream>
#include <map>
#include <utility>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

map<pair<int, int>, long long> edge;
long long *cityCost;
vector<int> *incident;

bool isPossible(int N, int s, int e) {
    queue<int> Q;
    bool *visit = new bool[N];
    for (int i = 0; i < N; i++)
        visit[i] = false;

    Q.push(s);
    int now, next;
    visit[s] = true;
    while (!Q.empty()) {
        now = Q.front();
        Q.pop();
        for (int i = 0; i < incident[now].size(); i++) {
            next = incident[now][i];
            if (next == e)
                return true;
            if (!visit[next]) {
                visit[next] = true;
                Q.push(next);
            }
        }
    }
    return false;
}
bool BellmanFord(long long* D, int end, int N) {
    for (int i = 1; i < N; i++) {
        for (auto it = edge.begin(); it != edge.end(); it++) {
            int s = it->first.first;
            int e = it->first.second;
            long long cost = it->second;
            if (D[s] != LLONG_MIN && D[s] + cost + cityCost[e] > D[e])
                D[e] = D[s] + cost + cityCost[e];
        }
    }

    for (auto it = edge.begin(); it != edge.end(); it++) {
        int S = it->first.first;
        int E = it->first.second;
        long long T = it->second;
        if (D[S] != LLONG_MIN && isPossible(N, E, end) && D[S] + T + cityCost[E] > D[E])
            return false;
    }
    return true;
}


int main() {
    long long *distance;
    int N, M, S, E, s, e;
    long long c, C;

    cin >> N >> S >> E >> M;
    cityCost = new long long[N];
    distance = new long long[N];
    incident = new vector<int>[N];
    for (int i = 0; i < N; i++)
        distance[i] = LLONG_MIN;

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        auto it = edge.find(make_pair(s, e));
        if (it == edge.end())
            edge.insert({make_pair(s, e), -c});
        else if (it->second < -c) {
            it->second = -c;
        }
        incident[s].push_back(e);
    }

    for (int i = 0; i < N; i++) {
        cin >> C;
        cityCost[i] = C;
    }

    bool bf;

    distance[S] = cityCost[S];
    bf = BellmanFord(distance, E, N);
    if (bf) {
        if (distance[E] == LLONG_MIN)
            cout << "gg";
        else
            cout << distance[E];
    }
    else {
        if (distance[E] == LLONG_MIN)
            cout << "gg";
        else
            cout << "Gee";
    }
}