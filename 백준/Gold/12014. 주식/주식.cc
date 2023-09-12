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

    int T, N, K, tmp;
    vector<int> stock, result;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        cin >> N >> K;

        for (int j = 0; j < N; j++) {
            cin >> tmp;
            stock.emplace_back(tmp);
        }

        result.emplace_back(stock[0]);
        for (int j = 1; j < N; j++) {
            if (result.back() < stock[j])
                result.emplace_back(stock[j]);
            else {
                int s = 0, e = result.size() - 1;
                int index;
                while (s <= e) {
                    int mid = (s + e) / 2;
                    if (result[mid] >= stock[j]) {
                        e = mid - 1;
                        index = mid;
                    } else
                        s = mid + 1;
                }
                result[index] = stock[j];
            }
        }
        cout << (K <= result.size()) << '\n';
        stock.clear();
        result.clear();
    }
}