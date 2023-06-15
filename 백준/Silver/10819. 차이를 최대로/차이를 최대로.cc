#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX = INT32_MIN;
int N;
vector<int> A;
vector<bool> visit;
int *arr;
int calculate(int* a) {
    int result = 0;
    for (int i = 0; i < N-1; i++)
        result += abs(a[i]-a[i+1]);
    return result;
}
void backtracking(int depth) {
    if (depth == N) {
        int final = calculate(arr);
        if (MAX < final)
            MAX = final;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            arr[depth] = A[i];
            backtracking(depth+1);
            visit[i] = false;
        }
    }
}


int main() {
    int n;
    cin >> N;

    arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        A.emplace_back(n);
        visit.emplace_back(false);
    }

    backtracking(0);
    cout << MAX;
}