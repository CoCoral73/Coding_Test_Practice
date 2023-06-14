#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> arr;
vector<bool> visit;
int answer = 0;
int cnt = 0;

void backtracking(int depth) {
    if (depth > 0 && answer == S) {
        cnt++;
    }
    if (depth == N) {
        return;
    }

    for (int i = depth; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            answer += arr[i];
            backtracking(i+1);
            answer -= arr[i];
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N >> S;

    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        arr.emplace_back(n);
        visit.emplace_back(false);
    }
    backtracking(0);
    cout << cnt;
}