#include <iostream>
#include <queue>
#include <string>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, K;
    bool alphabet[26] = { false };
    vector<string> words;
    int answer = 0;
public:
    BJ();
    void backtracking(int depth, int index);
    int getAnswer() { return answer; }
};

BJ::BJ() {
    cin >> N >> K;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        words.push_back(tmp);
    }
    alphabet['a'-'a'] = true;
    alphabet['c'-'a'] = true;
    alphabet['i'-'a'] = true;
    alphabet['n'-'a'] = true;
    alphabet['t'-'a'] = true;
}
void BJ::backtracking(int depth, int index) {
    if (K < 5) {
        cout << answer;
        exit(0);
    }
    if (depth == K-5) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            bool flag = true;
            for (int j = 0; j < words[i].length(); j++) {
                int alpha_num = words[i][j]-'a';
                if (!alphabet[alpha_num]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
        answer = max(answer, cnt);
        if (answer == N) {
            cout << answer;
            exit(0);
        }
        return;
    }

    for (int i = index; i < 26; i++) {
        if (alphabet[i])
            continue;
        alphabet[i] = true;
        backtracking(depth+1, i+1);
        alphabet[i] = false;
    }
}

int main() {
    fastIO;

    BJ a;
    a.backtracking(0, 1);
    cout << a.getAnswer();
}