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
    long long N, k;
    cin >> N >> k;

    long long s = 1, e = k;
    long long answer;
    while (s <= e) {
        long long m = (s + e) / 2;
        long long result = 0;
        for (int i = 1; i <= N; i++)
            result += min(m / i, N);
        if (result >= k) {
            answer = m;
            e = m - 1;
        }
        else
            s = m + 1;
    }
    cout << answer;
}