#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K, MIN = INT32_MAX, rst = 0;
    bool visited[200001] = {false};
    queue<pair<int, int>> Q;

    cin >> N >> K;
    visited[N] = true;
    Q.emplace(0, N);
    while (!Q.empty()) {
        int t = Q.front().first;
        int loc = Q.front().second;
        Q.pop();
        visited[loc] = true;

        if (loc == K) {
            if (MIN > t) {
                MIN = t;
                rst = 1;
            }
            else if (MIN == t)
                rst++;
            else
                break;
        }
        else if (loc < K) {
            if (loc-1 >= 0 && !visited[loc-1])
                Q.emplace(t+1, loc-1);
            if (loc+1 <= K && !visited[loc+1])
                Q.emplace(t+1, loc+1);
            if (2*loc <= 200000 && !visited[2*loc])
                Q.emplace(t+1, 2*loc);
        }
        else if (!visited[loc-1])
            Q.emplace(t+1, loc-1);
    }

    cout << MIN << '\n' << rst;
}