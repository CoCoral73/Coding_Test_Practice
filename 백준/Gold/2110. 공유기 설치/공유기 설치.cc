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

int get_result(vector<int> house, int D) {
    int last = -1;
    int answer = 0;

    for (int X : house) {
        if (last == -1 || X - last >= D) {
            answer++;
            last = X;
        }
    }
    return answer;
}

int main() {
    int N, C;
    vector<int> house;

    cin >> N >> C;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        house.emplace_back(tmp);
    }

    sort(house.begin(), house.end());
    long long s = 1, e = house.back() - house.front();
    long long answer = 0;
    while (s <= e) {
        long long mid = (s + e) / 2;
        int mid_result = get_result(house, mid);
        if (mid_result >= C) {
            answer = max(answer, mid);
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << answer;
}