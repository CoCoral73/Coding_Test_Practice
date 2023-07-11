#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastIO;

    int A, B;
    cin >> A >> B;

    long long answer;
    answer = (A+B)*(A-B);
    cout << answer;

    return 0;
}