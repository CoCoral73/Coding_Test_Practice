#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int blood[61][61][61];
int first_attack[6] = {9, 9, 3, 3, 1, 1};
int second_attack[6] = {3, 1, 9, 1, 9, 3};
int third_attack[6] = {1, 3, 1, 9, 3, 9};

signed main() {
    int N;
    cin >> N;

    vector<int> scv(3);
    for (int i = 0; i < N; i++)
        cin >> scv[i];
    sort(scv.begin(), scv.end(), greater<>());

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                blood[i][j][k] = INT32_MAX;
            }
        }
    }

    queue<vector<int>> Q;
    Q.push(scv);
    blood[scv[0]][scv[1]][scv[2]] = 0;

    while (!Q.empty()) {
        vector<int> front(Q.front());
        Q.pop();
        
        for (int i = 0; i < 6; i++) {
            int first = max(front[0] - first_attack[i], (int)0);
            int second = max(front[1] - second_attack[i], (int)0);
            int third = max(front[2] - third_attack[i], (int)0);
            vector<int> v = {first, second, third};
            sort(v.begin(), v.end(), greater<>());

            if (blood[v[0]][v[1]][v[2]] > blood[front[0]][front[1]][front[2]] + 1) {
                blood[v[0]][v[1]][v[2]] = blood[front[0]][front[1]][front[2]] + 1;
                if (v[0] != 0)
                    Q.push(v);
            }
        }
    }

    cout << blood[0][0][0];
}