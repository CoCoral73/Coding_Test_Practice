#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <memory.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N;
    vector<int> A;
    int B, C;
public:
    BJ();
    int solution();
};

BJ::BJ() {
    cin >> N;
    A = vector<int>(N);
    for (int &a : A)
        cin >> a;
    cin >> B >> C;

    cout << solution();
}
int BJ::solution() {
    int answer = 0;
    for (int a : A) {
        a -= min(B, a);
        answer++;
        if (a > 0) {
            if (a % C == 0) answer += (a / C);
            else answer += (a / C) + 1;
        }
    }
    return answer;
}

signed main() {
    fastIO;

    BJ Q13458;
}