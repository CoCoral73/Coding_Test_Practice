#include <iostream>
#include <queue>
#include <string>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    string A;
    string B;
    int MIN;
public:
    BJ();
    void Q1120();
};

BJ::BJ() {
    cin >> A >> B;
    MIN = A.length();
    for (int i = 0; i <= B.length()-A.length(); i++) {
        int m = 0;
        for (int j = 0; j < A.length(); j++)
            if (A[j] != B[i+j])
                m++;
        MIN = min(MIN, m);
    }
}
void BJ::Q1120() {
    cout << MIN;
}

int main() {
    fastIO;

    BJ a;
    a.Q1120();
}