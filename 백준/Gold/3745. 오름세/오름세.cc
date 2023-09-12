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

    int n, tmp;
    vector<int> port, result;
    while (true) {
        cin >> n;
        if (cin.eof()) break;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            port.emplace_back(tmp);
        }

        result.emplace_back(port[0]);
        for (int i = 1; i < n; i++) {
            if (result.back() < port[i])
                result.emplace_back(port[i]);
            else {
                int s = 0, e = result.size() - 1;
                int index = -1;
                while (s <= e) {
                    int mid = (s + e) / 2;
                    if (result[mid] >= port[i]) {
                        e = mid - 1;
                        index = mid;
                    } else
                        s = mid + 1;
                }
                result[index] = port[i];
            }
        }
        cout << result.size() << '\n';
        port.clear();
        result.clear();
    }
}