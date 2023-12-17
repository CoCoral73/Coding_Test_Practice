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
    int N, S;
    int arr[40];
    map<int, int> left, right;
public:
    BJ();
    void getHalf(int index, int end, int sum);
};

BJ::BJ() {
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    getHalf(0, N/2, 0);
    getHalf(N/2, N, 0);

    map<int, int>::iterator iter;
    int answer = 0;
    for (iter = left.begin(); iter != left.end(); iter++) {
        answer += iter->second * right[S-iter->first];
    }
    if (S == 0) answer -= 1;
    cout << answer;
}
void BJ::getHalf(int index, int end, int sum) {
    if (index == end) {
        if (end == N) right[sum] += 1;
        else left[sum] += 1;
        return;
    }

    getHalf(index+1, end, sum + arr[index]);
    getHalf(index+1, end, sum);
}

signed main(){
    fastIO;

    BJ Q1208;
}
