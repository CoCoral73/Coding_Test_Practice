#include <iostream>
using namespace std;

int main() {
    int n, k, v;
    cin >> n >> k;

    int *D = new int[k+1];
    D[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> v;
        for (int j = 1; j <= k; j++) {
            if (i == 0) {
                if (j % v == 0)
                    D[j] = 1;
                else
                    D[j] = 0;
            }
            else {
                if (j == v)
                    D[j]++;
                else if (j-v > 0)
                    D[j] += D[j-v];
            }
        }
    }
    cout << D[k];
}