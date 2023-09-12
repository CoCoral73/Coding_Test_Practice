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

    int N, tmp;
    cin >> N;

    vector<int> Switch(N);
    for (int &s : Switch)
        cin >> s;
    vector<int> Lamp(N);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        Lamp[tmp-1] = i;
    }

    vector<int> result;
    result.emplace_back(Switch[0]);
    vector<int> dp(N);
    dp[Switch[0]-1] = 1;
    for (int i = 1; i < N; i++) {
        if (Lamp[result.back()-1] < Lamp[Switch[i]-1]) {
            result.emplace_back(Switch[i]);
            dp[Switch[i]-1] = result.size();
        }
        else {
            int s = 0, e = result.size()-1;
            int index;
            while (s <= e) {
                int m = (s + e) / 2;
                if (Lamp[result[m]-1] >= Lamp[Switch[i]-1]) {
                    index = m;
                    e = m - 1;
                }
                else
                    s = m + 1;
            }
            result[index] = Switch[i];
            dp[Switch[i]-1] = index + 1;
        }
    }
    int size = result.size(), last = N;
    cout << size << '\n';
    vector<int> answer;
    for (int i = N-1; i >= 0; i--) {
        if (dp[Switch[i]-1] == size && Lamp[Switch[i]-1] < last) {
            answer.emplace_back(Switch[i]);
            last = Lamp[Switch[i]-1];
            size--;
        }
    }
    sort(answer.begin(), answer.end());
    for (int a : answer)
        cout << a << " ";
}