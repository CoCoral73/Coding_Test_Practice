#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class BJ {
    int k;
    vector<char> V;
    bool visit[10] = {false};
    char *MIN;
    char *MAX;
    char *NOW;
public:
    BJ();
    void backtracking(int depth);
    void printAnswer();
};

BJ::BJ() {
    cin >> k;
    char ch;
    for (int i = 0; i < k; i++) {
        cin >> ch;
        V.emplace_back(ch);
    }
    NOW = new char[k+1];
    MIN = new char[k+1];
    MIN[0] = '-';
    MAX = new char[k+1];
    MAX[0] = '-';
}
void BJ::backtracking(int depth) {
    if (depth == k+1) {
        if (MIN[0] == '-' || MIN[0] != '-' && NOW < MIN)
            strcpy(MIN, NOW);
        if (MAX[0] == '-' || MAX[0] != '-' && NOW > MAX)
            strcpy(MAX, NOW);
        return;
    }

    if (depth == 0) {
        for (int i = 0; i < 10; i++) {
            visit[i] = true;
            NOW[depth] = i + '0';
            backtracking(depth+1);
            visit[i] = false;
        }
    }
    else {
        for (int i = 0; i < 10; i++) {
            if (!visit[i]) {
                //cout << int(NOW[depth-1]) << endl;
                if (V[depth-1] == '<' && NOW[depth-1]-'0' < i) {
                    visit[i] = true;
                    NOW[depth] = i + '0';
                    backtracking(depth+1);
                    visit[i] = false;
                }
                if (V[depth-1] == '>' && NOW[depth-1]-'0' > i) {
                    visit[i] = true;
                    NOW[depth] = i + '0';
                    backtracking(depth+1);
                    visit[i] = false;
                }
            }
        }
    }
}
void BJ::printAnswer() {
    cout << string(MIN) << '\n';
    cout << string(MAX);
}
int main() {
    BJ a;
    a.backtracking(0);
    a.printAnswer();
}