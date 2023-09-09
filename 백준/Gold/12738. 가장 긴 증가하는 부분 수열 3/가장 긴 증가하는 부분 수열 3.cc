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

    vector<int> A(N);
    for (int &a : A)
        cin >> a;

    vector<int> arr = { A.front() };
    for (int i = 1; i < N; i++) {
        if (arr.back() < A[i])
            arr.emplace_back(A[i]);
        else {
            int s = 0, e = arr.size() - 1;
            int index = -1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (arr[mid] < A[i])
                    s = mid + 1;
                else {
                    if (index == -1 || arr[mid] - A[i] < arr[index] - A[i])
                        index = mid;
                    e = mid - 1;
                }
            }
            arr[index] = A[i];
        }
    }
    cout << arr.size();
}