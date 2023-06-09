#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M, n;
    vector<long long> A;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> n;
        A.emplace_back(n);
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        long long sum = A[i];
        if (sum > M)
            continue;
        else if (sum == M) {
            answer++;
            continue;
        }
        for (int j = i+1; j < N; j++) {
            sum += A[j];
            if (sum > M)
                break;
            else if (sum == M) {
                answer++;
                break;
            }
        }
    }

    cout << answer;
}