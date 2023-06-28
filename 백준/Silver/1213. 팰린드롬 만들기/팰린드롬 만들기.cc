#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastIO;

    string name;
    cin >> name;
    string answer(name);

    int alpha[26] = {0};
    for (int i = 0; i < name.length(); i++)
        alpha[name[i]-'A']++;

    int L = name.length(), index = 0;
    if (L % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            while (alpha[i] > 0) {
                if (alpha[i] % 2 == 1) {
                    cout << "I'm Sorry Hansoo";
                    exit(0);
                }
                answer[index] = 'A' + i;
                answer[L-index-1] = 'A' + i;
                index++;
                alpha[i] -= 2;
            }
        }
    }
    else {
        bool flag = false;
        for (int i = 0; i < 26; i++) {
            while (alpha[i] > 0) {
                if (alpha[i] % 2 == 0) {
                    answer[index] = 'A' + i;
                    answer[L-index-1] = 'A' + i;
                    index++;
                    alpha[i] -= 2;
                }
                else {
                    if (flag) {
                        cout << "I'm Sorry Hansoo";
                        exit(0);
                    }
                    answer[L/2] = 'A' + i;
                    flag = true;
                    alpha[i]--;
                }
            }
        }
    }
    cout << answer;
}