#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int N, K;
    vector<int> PowerBar;
    vector<int> device;
    map<int, queue<int>> info;
public:
    BJ();
    void Q1700();
};

BJ::BJ() {
    cin >> N >> K;
    int n;
    for (int i = 0; i < K; i++) {
        cin >> n;
        device.emplace_back(n);
        if (info.find(n) == info.end()) {
            queue<int> Q;
            Q.push(i);
            info.insert({n, Q});
        }
        else {
            info[n].push(i);
        }
    }
}
void BJ::Q1700() {
    int answer = 0;
    for (int i = 0; i < K; i++) {
        if (find(PowerBar.begin(), PowerBar.end(), device[i]) != PowerBar.end()) {
            info[device[i]].pop();
            continue;
        }
        else {
            if (PowerBar.size() < N) {
                PowerBar.emplace_back(device[i]);
                info[device[i]].pop();
            }
            else {
                int n = 0, index = 0;
                for (int j = 0; j < N; j++) {
                    if (info[PowerBar[j]].empty()) {
                        n = j;
                        break;
                    }
                    int I = info[PowerBar[j]].front();
                    if (I > index) {
                        n = j;
                        index = I;
                    }
                }
                PowerBar[n] = device[i];
                info[PowerBar[n]].pop();
                answer++;
            }
        }
    }
    cout << answer;
}

int main() {
    fastIO;

    BJ a;
    a.Q1700();
}