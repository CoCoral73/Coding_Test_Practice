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

int get_result(vector<int> house, int D) {
    int last = -1;
    int answer = 0;

    for (int X : house) {
        if (last == -1 || X - last >= D) {
            answer++;
            last = X;
        }
    }
    return answer;
}

int main() {
    int N;
    vector<int> pHs;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int pH;
        cin >> pH;
        pHs.emplace_back(pH);
    }

    sort(pHs.begin(), pHs.end());
    int s = 0, e = N-1;
    pair<int, int> answer = { pHs[s], pHs[e]} ;
    while (s + 1 < e) {
        if (abs(pHs[s+1] + pHs[e]) < abs(pHs[s] + pHs[e-1]))
            s++;
        else
            e--;
        answer = abs(pHs[s] + pHs[e]) < abs(answer.first + answer.second) ? make_pair(pHs[s], pHs[e]) : answer;
    }
    cout << answer.first << " " << answer.second;
}

