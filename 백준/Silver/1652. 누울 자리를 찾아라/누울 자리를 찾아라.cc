#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    int N;
    string *room;

    cin >> N;
    room = new string[N];
    for (int i = 0; i < N; i++)
        cin >> room[i];

    int s, e;
    int answer1 = 0, answer2 = 0;
    for (int i = 0; i < N; i++) {
        s = 0;
        while (true) {
            while (s < N && room[i][s] == 'X') s++;
            if (s >= N)
                break;
            e = s;
            while (e < N && room[i][e] == '.') e++;
            if (e - s >= 2)
                answer1++;
            if (e >= N)
                break;
            s = e;
        }
        s = 0;
        while (true) {
            while (s < N && room[s][i] == 'X') s++;
            if (s >= N)
                break;
            e = s;
            while (e < N && room[e][i] == '.') e++;
            if (e - s >= 2)
                answer2++;
            if (e >= N)
                break;
            s = e;
        }
    }

    cout << answer1 << ' ' << answer2;
}