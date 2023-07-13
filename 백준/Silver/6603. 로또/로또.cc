#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int result[6];
void backtracking(vector<int> S, int depth, int start) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i < S.size(); i++) {
        result[depth] = S[i];
        backtracking(S, depth+1, i+1);
    }
}
int main() {
    fastIO;

    int k;
    while (true) {
        cin >> k;
        if (k == 0)
            break;
        vector<int> S;
        int s;
        for (int i = 0; i < k; i++) {
            cin >> s;
            S.emplace_back(s);
        }
        backtracking(S, 0, 0);
        cout << '\n';
    }
}