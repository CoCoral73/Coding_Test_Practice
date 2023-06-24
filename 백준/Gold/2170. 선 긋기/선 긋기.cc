#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastIO;

    long long N, x, y;
    vector<pair<long long, long long>> line;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        line.emplace_back(x, y);
    }
    sort(line.begin(), line.end());

    long long s = line[0].first;
    long long e = line[0].second;
    long long length = 0;
    for (int i = 1; i < line.size(); i++) {
        tie(x, y) = line[i];
        if (x <= e) {
            e = max(e, y);
        }
        else {
            length += e-s;
            s = x;
            e = y;
        }
    }
    length += e-s;
    cout << length;
}