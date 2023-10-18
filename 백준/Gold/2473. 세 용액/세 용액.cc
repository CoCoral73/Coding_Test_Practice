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
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N;
    vector<int> pHs;
    int answer[3];
    int MIN = LONG_LONG_MAX;
public:
    BJ();
    void binary_search();
    int tri_sum(int a, int b, int c) { return abs(a + b + c);}
};

BJ::BJ() {
    cin >> N;
    pHs = vector<int>(N);
    for (int &pH : pHs)
        cin >> pH;
    sort(pHs.begin(), pHs.end());

    binary_search();
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2];
}
void BJ::binary_search() {
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            int s = j+1, e = N-1, mid;
            while (s <= e) {
                mid = (s + e) / 2;
                int mid_value = tri_sum(pHs[i], pHs[j], pHs[mid]);
                if (mid_value > tri_sum(pHs[i], pHs[j], pHs[mid-1]))
                    e = mid - 1;
                else if (mid_value > tri_sum(pHs[i], pHs[j], pHs[mid+1]))
                    s = mid + 1;
                else
                    break;
            }
            if (MIN > tri_sum(pHs[i], pHs[j], pHs[mid])) {
                MIN = tri_sum(pHs[i], pHs[j], pHs[mid]);
                answer[0] = pHs[i];
                answer[1] = pHs[j];
                answer[2] = pHs[mid];
            }
        }
    }
}

signed main() {
    fastIO;

    BJ Q2473;
}
