#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string name;
    vector<string> v;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name;
        v.emplace_back(name);
    }
    
    int index = 0;
    while (v[index] != "KBS1") {
        index += 1;
        cout << 1;
    }
    while (index > 0) {
        swap(v[index-1], v[index]);
        index -= 1;
        cout << 4;
    }
    while (v[index] != "KBS2") {
        index += 1;
        cout << 1;
    }
    while (index > 1) {
        swap(v[index-1], v[index]);
        index -= 1;
        cout << 4;
    }
}