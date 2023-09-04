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

long long get_height(vector<int> trees, int H) {
    long long total = 0;
    for (int tree : trees)
        total += max(0, tree - H);
    return total;
}

int main() {
    int N, M;
    vector<int> trees;
    int s = 0, e = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tree;
        cin >> tree;
        trees.emplace_back(tree);
        e = max(e, tree);
    }

    int mid;
    long long mid_result;
    int answer = 0;
    while (s <= e) {
        mid = (s + e) / 2;
        mid_result = get_height(trees, mid);
        if (mid_result >= M) {
            answer = max(answer, mid);
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << answer;
}