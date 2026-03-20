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

int f, s, g, u, d;
int isVisited[1000001];

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(isVisited, isVisited + 1000001, INF);
    
    cin >> f >> s >> g >> u >> d;
    bfs();
    
}

void bfs() {
    queue<int> q;
    q.emplace(s);
    isVisited[s] = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == g) {
            cout << isVisited[x];
            return;
        }
        
        if (x + u <= f && isVisited[x+u] > isVisited[x] + 1) {
            isVisited[x+u] = isVisited[x] + 1;
            q.emplace(x+u);
        }
        if (x - d >= 1 && isVisited[x-d] > isVisited[x] + 1) {
            isVisited[x-d] = isVisited[x] + 1;
            q.emplace(x-d);
        }
    }
    cout << "use the stairs";
}
