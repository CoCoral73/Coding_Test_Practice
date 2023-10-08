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

class BJ {
    int N;
    string formula;
    int MAX = INT32_MIN;
    vector<int> num;
    vector<int> oper;
public:
    BJ();
    int calculate1(int x, char op, int y);
    void calculate2();
    void solution(int now, bool flag);
    int convertN(char ch) { return ch - '0'; }
};

BJ::BJ() {
    cin >> N;
    cin >> formula;
    if (N == 1) {
        cout << convertN(formula[0]);
        exit(0);
    }
    solution(1, true);
    cout << MAX;
}
int BJ::calculate1(int x, char op, int y) {
    if (op == '+')
        return x + y;
    if (op == '-')
        return x - y;
    return x * y;
}
void BJ::calculate2() {
    int answer = num[0];
    for (int i = 0; i < oper.size(); i++) {
        answer = calculate1(answer, oper[i], num[i+1]);
    }
    MAX = max(MAX, answer);
}

void BJ::solution(int now, bool flag) {
    if (now >= N) {
        calculate2();
        return;
    }
    //() O
    if (flag) {
        num.emplace_back(calculate1(convertN(formula[now - 1]), formula[now], convertN(formula[now + 1])));
        solution(now + 2, false);
        num.pop_back();

        num.emplace_back(convertN(formula[now-1]));
        oper.emplace_back(formula[now]);
        if (now + 1 == N - 1)
            num.emplace_back(convertN(formula[now+1]));
        solution(now + 2, true);
        num.pop_back();
        oper.pop_back();
        if (now + 1 == N - 1)
            num.pop_back();
    }
    else {
        oper.emplace_back(formula[now]);
        if (now + 1 == N - 1)
            num.emplace_back(convertN(formula[now+1]));
        solution(now + 2, true);
        oper.pop_back();
        if (now + 1 == N - 1)
            num.pop_back();
    }
}

signed main() {
    fastIO;

    BJ Q16637;
}