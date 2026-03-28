//
//  main.cpp
//  CppPractice
//
//  Created by 김정원 on 3/13/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;

int N, K;
int isVisited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    fill(isVisited, isVisited + 100001, INF);
    
    queue<int> q;
    q.push(N);
    isVisited[N] = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == K) break;
        
        if (x-1 >= 0 && isVisited[x-1] > isVisited[x] + 1) {
            q.push(x-1);
            isVisited[x-1] = isVisited[x] + 1;
        }
        if (x+1 <= 100000 && isVisited[x+1] > isVisited[x] + 1) {
            q.push(x+1);
            isVisited[x+1] = isVisited[x] + 1;
        }
        if (2*x <= 100000 && isVisited[2*x] > isVisited[x]) {
            q.push(2*x);
            isVisited[2*x] = isVisited[x];
        }
    }
    cout << isVisited[K];
}
