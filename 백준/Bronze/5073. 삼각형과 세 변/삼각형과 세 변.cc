#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    vector<int> v;
    
    while (true) {
        cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0) { return 0; }
        v = {a, b, c};
        sort(v.begin(), v.end());
        
        if (v[2] >= v[0] + v[1]) {
            cout << "Invalid" << '\n';
        } else {
            if (v[0] == v[1] && v[1] == v[2]) {
                cout << "Equilateral" << '\n';
            } else if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) {
                cout << "Scalene" << '\n';
            } else {
                cout << "Isosceles" << '\n';
            }
        }
    }
}
