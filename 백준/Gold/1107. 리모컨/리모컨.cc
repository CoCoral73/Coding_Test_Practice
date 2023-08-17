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

class BJ {
    int answer;
    int N, M;
    bool avail[10] = { true, true, true, true, true, true, true, true, true, true};
public:
    BJ();
    int check(int channel);
    void solution();
};

BJ::BJ() {
    cin >> N;
    cin >> M;
    int btn;
    for (int i = 0; i < M; i++) {
        cin >> btn;
        avail[btn] = false;
    }
}
int BJ::check(int channel) {
    if (channel < 0)
        return -1;
    if (channel == 0) {
        if (avail[0])
            return 1;
        return -1;
    }
    int count = 0;
    while (channel > 0) {
        if (!avail[channel % 10])
            return -1;
        count++;
        channel /= 10;
    }
    return count;
}
void BJ::solution() {
    answer = abs(N-100);
    int i = 0;
    while (i < abs(N-100)) {
        int up = check(N+i);
        int down = check(N-i);
        if (up != -1)
            answer = min(answer, up + i);
        if (down != -1)
            answer = min(answer, down + i);
        if (up != -1 || down != -1)
            break;
        i++;
    }
    cout << answer;
}

int main() {
    BJ a;
    a.solution();
}