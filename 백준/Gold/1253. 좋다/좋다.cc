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

    int N;
    cin >> N;

    vector<long long> A(N);
    for (long long &a : A)
        cin >> a;
    sort(A.begin(), A.end());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int first = 0; first < N; first++) {
            if (first == i) continue;
            bool flag = false;
            int s = first + 1, e = N - 1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (mid == i) {
                    if (A[first] + A[mid] > A[i])
                        e = mid - 1;
                    else
                        s = mid + 1;
                }
                else {
                    if (A[first] + A[mid] > A[i])
                        e = mid - 1;
                    else if (A[first] + A[mid] < A[i])
                        s = mid + 1;
                    else {
                        flag = true;
                        answer++;
                        break;
                    }
                }
            }
            if (flag) { break; }
        }
    }
    cout << answer;
}