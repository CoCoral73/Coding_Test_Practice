#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> visit;
int* answer;

void backtracking(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            answer[depth] = i+1;
            backtracking(depth+1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N;
    answer = new int[N];
    for (int i = 0; i < N; i++)
        visit.emplace_back(false);
    backtracking(0);
}