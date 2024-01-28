#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <memory.h>
#define int long long
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N;
    vector<int> original, index;
    vector<int> answer;
public:
    BJ();
};

BJ::BJ() {
    cin >> N;
    index = vector<int>(1000001);
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        original.emplace_back(x);
        index[x] = i+1;
    }

    answer = vector<int>(N);
    for (int x : original) {
        for (int i = 2; x*i <= 1000001; i++) {
            int y = x*i;
            if (index[y] == 0) continue;
            answer[index[x]-1]++;
            answer[index[y]-1]--;
        }
    }

    for (int i = 0; i < N; i++)
        cout << answer[i] << ' ';
}

signed main() {
    fastIO;

    BJ Q27172;
}