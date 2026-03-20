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
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int t, n;
int isVisited[300][300];

queue<pii> q;
pii dest;

int bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int r, c;
    
    cin >> t;
    while (t--) {
        fill(&isVisited[0][0], &isVisited[0][0] + 300 * 300, INF);
        
        cin >> n;
        cin >> r >> c;
        q.emplace(r, c);
        isVisited[r][c] = 0;
        
        cin >> r >> c;
        dest = {r, c};
        
        cout << bfs() << '\n';
        q = queue<pii>();
    }
}

int bfs() {
    while (!q.empty()) {
        pii front = q.front();
        q.pop();
        
        if (front == dest) {
            return isVisited[front.first][front.second];
        }
        
        for (int i = 0; i < 8; i++) {
            int r = front.first + dr[i];
            int c = front.second + dc[i];
            
            if (r < 0 || r >= n || c < 0 || c >= n) continue;
            if (isVisited[r][c] <= isVisited[front.first][front.second] + 1) continue;
            
            isVisited[r][c] = isVisited[front.first][front.second] + 1;
            q.emplace(r, c);
        }
        
    }
    return 0;
}
