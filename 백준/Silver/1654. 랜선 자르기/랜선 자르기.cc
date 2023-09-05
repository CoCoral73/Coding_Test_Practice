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

long long get_result(vector<int> lans, int L) {
    long long total = 0;
    for (int lan : lans)
        total += lan / L;
    return total;
}

int main() {
    int K, N;
    vector<int> lans;
    long long s = 1, e = 1;

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        long long lan;
        cin >> lan;
        lans.emplace_back(lan);
        e = max(e, lan);
    }

    long long mid;
    long long mid_result;
    long long answer = 1;
    while (s <= e) {
        mid = (s + e) / 2;
        mid_result = get_result(lans, mid);
        if (mid_result >= N) {
            answer = max(answer, mid);
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << answer;
}