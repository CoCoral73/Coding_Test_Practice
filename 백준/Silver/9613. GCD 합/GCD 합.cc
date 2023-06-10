#include <iostream>
#include <vector>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a%b);
}

int main() {
    long long t, n, num;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<long long> v;
        for (int j = 0; j < n; j++) {
            cin >> num;
            v.emplace_back(num);
        }
        long long sum = 0;
        for (int j = 0; j < v.size(); j++) {
            for (int k = j+1; k < v.size(); k++)
                sum += GCD(max(v[j],v[k]), min(v[j], v[k]));
        }
        cout << sum << '\n';
    }
}