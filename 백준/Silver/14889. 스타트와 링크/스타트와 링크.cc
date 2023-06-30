#include <iostream>
#include <vector>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N;
    int **S;
    bool *visit;
    int *team1;
    int *team2;
    int answer = INT32_MAX;
public:
    BJ();
    void backtracking(int depth, int start);
    void printAnswer();
};

BJ::BJ() {
    cin >> N;
    S = new int*[N];
    visit = new bool[N];
    for (int i = 0; i < N; i++) {
        S[i] = new int[N];
        for (int j = 0; j < N; j++)
            cin >> S[i][j];
        visit[i] = false;
    }
    team1 = new int[N/2];
    team2 = new int[N/2];
}
void BJ::backtracking(int depth, int start) {
    if (depth == N/2) {
        int index = 0;
        for (int i = 0; i < N; i++) {
            if (!visit[i])
                team2[index++] = i;
        }

        int s1 = 0, s2 = 0;
        for (int i = 0; i < N/2; i++) {
            for (int j = i+1; j < N/2; j++) {
                if (i == j)
                    continue;
                s1 += S[team1[i]][team1[j]] + S[team1[j]][team1[i]];
                s2 += S[team2[i]][team2[j]] + S[team2[j]][team2[i]];
            }
        }
        answer = min(answer, abs(s1-s2));
        if (answer == 0) {
            cout << answer;
            exit(0);
        }
        return;
    }

    for (int i = start; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            team1[depth] = i;
            backtracking(depth+1, i+1);
            visit[i] = false;
        }
    }
}
void BJ::printAnswer() {
    cout << answer;
}
int main() {
    fastIO;
    BJ a;
    a.backtracking(0, 0);
    a.printAnswer();
}