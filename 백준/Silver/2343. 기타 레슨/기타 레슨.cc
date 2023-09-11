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

int main() {
    fastIO;

    int N, M;
    cin >> N >> M;

    vector<int> guitars(N);
    int MAX = INT32_MIN;
    int SUM = 0;
    for (int &g : guitars) {
        cin >> g;
        MAX = max(MAX, g);
        SUM += g;
    }

    int s = MAX, e = SUM;
    while (s < e) {
        int m = (s + e) / 2;
        int count = 0, total = 0;
        for (int i = 0; i < N; i++) {
            total += guitars[i];
            if (i == N-1 || total + guitars[i+1] > m) {
                count++;
                total = 0;
            }
        }
        if (count > M)
            s = m + 1;
        else
            e = m;
    }
    cout << e;
}