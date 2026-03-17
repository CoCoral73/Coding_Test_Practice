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

int T, M, N, K;
int grid[50][50];
bool visited[50][50];

void bfs(int r, int c);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        
        fill((int *)grid, (int *)grid + 50 * 50, 0);
        fill((bool *)visited, (bool *)visited + 50 * 50, 0);
        
        for (int i = 0, x, y; i < K; i++) {
            cin >> x >> y;
            grid[y][x] = 1;
        }
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }
}

void bfs(int r, int c) {
    queue<pii> q;
    
    visited[r][c] = true;
    q.emplace(r, c);
    
    int y, x;
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int yy = y + dr[i];
            int xx = x + dc[i];
            
            if (yy < 0 || yy >= N || xx < 0 || xx >= M) { continue; }
            if (grid[yy][xx] == 0 || visited[yy][xx]) { continue; }
            
            visited[yy][xx] = true;
            q.emplace(yy, xx);
        }
    }
}
