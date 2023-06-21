#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, *P;
    int *DP;

    cin >> N;
    P = new int[N+1];
    DP = new int[N+1];
    for (int i = 1; i <= N; i++)
        cin >> P[i];

    DP[0] = 0;
    for (int i = 1; i <= N; i++) {
        DP[i] = P[i];
        for (int j = 1; j <= i/2; j++)
            DP[i] = max(DP[i], DP[i-j]+DP[j]);
        //cout << DP[i] << ' ';
    }
    cout << DP[N];

    delete P;
    delete DP;
}