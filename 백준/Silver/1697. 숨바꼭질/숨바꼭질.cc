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
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N, K;
int visited[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(visited, visited + 200001, INF);
    
    cin >> N >> K;
    
    queue<int> q;
    
    visited[N] = 0;
    q.emplace(N);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == K) {
            cout << visited[x];
            return 0;
        }
        
        if (x - 1 >= 0 && visited[x-1] > visited[x] + 1) {
            visited[x-1] = visited[x] + 1;
            q.emplace(x-1);
        }
        
        if (x + 1 <= 200000 && visited[x+1] > visited[x] + 1) {
            visited[x+1] = visited[x] + 1;
            q.emplace(x+1);
        }
        
        if (2*x <= 200000 && visited[2*x] > visited[x] + 1) {
            visited[2*x] = visited[x] + 1;
            q.emplace(2*x);
        }
    }
}
