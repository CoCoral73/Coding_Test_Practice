#include <iostream>
#include <string>
#include <vector>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int MIN;
vector<string> mbti;

void dfs(string select[3], int N, int depth, int start) {
    if (depth == 3) {
        int answer = 0;
        for (int i = 0; i < 4; i++) {
            if (select[0][i] != select[1][i])
                answer++;
            if (select[0][i] != select[2][i])
                answer++;
            if (select[1][i] != select[2][i])
                answer++;
        }
        MIN = min(MIN, answer);
        return;
    }

    for (int i = start; i < N; i++) {
        select[depth] = mbti[i];
        dfs(select, N, depth+1, i+1);
        if (MIN == 0)
            return;
    }
}

int main() {
    fastIO;
    int T, N;
    string select[3];
    string tmp;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        mbti.clear();
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            mbti.emplace_back(tmp);
        }
        MIN = INT32_MAX;
        dfs(select, N, 0, 0);
        cout << MIN << '\n';
    }

}