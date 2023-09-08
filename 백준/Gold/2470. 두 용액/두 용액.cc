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
    vector<int> pHs(N);
    for (int &pH : pHs)
        cin >> pH;

    sort(pHs.begin(), pHs.end());
    pair<int, int> answer = { pHs.front(), pHs.back() } ;
    for (int i = 0; i < N-1; i++) {
        int s = i+1, e = N-1, mid;
        while (s <= e) {
            mid = (s + e) / 2;
            int mid_value = abs(pHs[i] + pHs[mid]);
            if (mid_value > abs(pHs[i] + pHs[mid-1]))
                e = mid - 1;
            else if (mid_value > abs(pHs[i] + pHs[mid+1]))
                s = mid + 1;
            else
                break;
        }
        answer = abs(answer.first + answer.second) > abs(pHs[i] + pHs[mid]) ? make_pair(pHs[i], pHs[mid]) : answer;
    }
    cout << answer.first << " " << answer.second;
}

