#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastIO;

    int N, A;
    vector<int> rank;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        rank.emplace_back(A);
    }
    sort(rank.begin(), rank.end());

    int now = 1;
    long long answer = 0;
    for (int i = 0; i < N; i++) {
        answer += abs(rank[i]-now);
        now++;
    }
    cout << answer;
}