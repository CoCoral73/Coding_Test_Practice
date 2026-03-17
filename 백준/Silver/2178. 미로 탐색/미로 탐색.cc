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

int N, M;
vector<string> maze;
int visited[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        maze.push_back(str);
    }
    
    fill(&visited[0][0], &visited[0][0] + 10000, INF);
    
    queue<pii> q;
    
    visited[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();
        
        if (pii(r, c) == pii(N-1, M-1)) {
            cout << visited[r][c];
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int y = r + dr[i];
            int x = c + dc[i];
            
            if (y < 0 || y >= N || x < 0 || x >= M) { continue; }
            if (maze[y][x] == '0') { continue; }
            if (visited[y][x] <= visited[r][c] + 1) { continue; }
            
            visited[y][x] = visited[r][c] + 1;
            q.emplace(y, x);
        }
    }
}
