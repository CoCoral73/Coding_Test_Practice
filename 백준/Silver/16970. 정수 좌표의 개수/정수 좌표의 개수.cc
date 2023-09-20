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
    int N, M, K;
    bool coordinate[51][51];
    pair<int, int> dots[2];
    int answer;
public:
    BJ();
    void solution(int depth);
};

BJ::BJ() {
    cin >> N >> M >> K;
    answer = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++)
            coordinate[i][j] = false;
    }

    solution(0);
    cout << answer/2;
}
void BJ::solution(long long depth) {
    if (depth == 2) {
        int a = dots[1].first - dots[0].first;
        int b = dots[1].second - dots[0].second;
        int c = dots[1].first;
        int d = dots[1].second * a;
        int x = min(dots[0].first, dots[1].first), X = max(dots[0].first, dots[1].first);
        int y = min(dots[0].second, dots[1].second), Y = max(dots[0].second, dots[1].second);

        int count = 0;
        for (int i = x; i <= X; i++) {
            for (int j = y; j <= Y; j++) {
                if (a*j == b*(i-c)+d)
                    count++;
            }
        }

        if (count == K)
            answer++;

        return;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (coordinate[i][j])
                continue;
            coordinate[i][j] = true;
            dots[depth] = {i, j};
            solution(depth+1);
            coordinate[i][j] = false;
        }
    }
}

signed main() {
    fastIO;

    BJ a;
}