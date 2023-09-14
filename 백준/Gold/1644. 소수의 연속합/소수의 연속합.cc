#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<bool> v(N+1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i < N; i++) {
        if (i != 2 && i % 2 == 0)
            continue;
        for (int j = 2; i*j <= N; j++)
            v[i*j] = false;
    }

    vector<int> prime;
    prime.emplace_back(0);
    for (int i = 2; i <= N; i++) {
        if (!v[i]) continue;
            prime.emplace_back(prime.back() + i);
    }

    int e = prime.size() - 1, s = e-1;
    int answer = 0;
    while (s >= 0) {
        if (prime[e] - prime[s] == N) {
            answer++;
            e--, s--;
        }
        else if (prime[e] - prime[s] > N) {
            e--;
            s = e-1;
        }
        else {
            s--;
        }
    }
    cout << answer;

}