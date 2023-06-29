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

    int N, s;
    vector<int> score;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        score.emplace_back(s);
    }

    int answer = 0;
    for (int i = N-2; i >= 0; i--) {
        if (score[i+1]-1 < score[i]) {
            answer += score[i] - (score[i + 1] - 1);
            score[i] = score[i + 1] - 1;
        }
    }
    cout << answer;
}