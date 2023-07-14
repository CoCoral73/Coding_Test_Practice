#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastIO;

    int N, S, n;
    vector<long long> arr = {0};
    cin >> N >> S;
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        if (n >= S) {
            cout << 1;
            return 0;
        }
        arr.emplace_back(n);
        total += n;
    }

    if (total < S) {
        cout << 0;
        return 0;
    }

    int head = 0, tail = 0;
    int answer = N;
    total = 0;
    while (tail <= N) {
        if (total < S)
            total += arr[++tail];
        else {
            answer = min(answer, tail-head+1);
            total -= arr[head++];
        }
    }

    cout << answer;
}