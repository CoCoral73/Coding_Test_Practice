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
    int N, L;
    vector<int> A;
public:
    BJ();
    void solution();
};

BJ::BJ() {
    cin >> N >> L;
    A = vector<int>(N);
    for (int &a: A)
        cin >> a;

    solution();
}
void BJ::solution() {
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        if (!dq.empty() && dq.front() < i - L + 1) dq.pop_front();
        
        if (dq.empty())
            cout << A[i] << ' ';
        else
            cout << min(A[dq.front()], A[i]) << ' ';
        while (!dq.empty() && A[dq.back()] > A[i]) dq.pop_back();
        dq.push_back(i);
    }
}

signed main() {
    fastIO;

    BJ Q11003;
}