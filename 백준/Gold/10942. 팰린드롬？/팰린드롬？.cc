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
    fastIO;

    int N, M, S, E;
    cin >> N;

    vector<int> arr(N);
    for (int &a : arr)
        cin >> a;

    bool **answer = new bool *[N];
    for (int i = 0; i < N; i++) {
        answer[i] = new bool[N];
        for (int j = 0; j < i; j++)
            answer[i][j] = false;
        answer[i][i] = true;
        if (i - 1 >= 0)
            answer[i][i-1] = true;
    }

    for (int i = N-1; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            if (arr[i] == arr[j] && answer[i+1][j-1])
                answer[i][j] = true;
            else
                answer[i][j] = false;
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << answer[S-1][E-1] << '\n';
    }
}