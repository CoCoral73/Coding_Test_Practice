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

int N;
int matrix[100][100];
int visited[100][100];
int cnt, answer = INF;

void dfs(int n, int i, int j);
int bfs(int i, int j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                dfs(++cnt, i, j);
            }
        }
    }
    
    fill(&visited[0][0], &visited[0][0] + 100 * 100, INF);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == cnt) goto output;
            if (matrix[i][j] != 0 && visited[i][j] == INF) {
                answer = min(answer, bfs(i, j));
                if (answer == 1) goto output;
            }
        }
    }
    
    output:
    cout << answer;
}

void dfs(int n, int i, int j) {
    matrix[i][j] = n;
    visited[i][j] = true;
    
    for (int a = 0; a < 4; a++) {
        int r = i + dr[a];
        int c = j + dc[a];
        
        if (r < 0 || r >= N || c < 0 || c >= N) continue;
        if (visited[r][c]) continue;
        if (matrix[r][c] != 1) continue;
        dfs(n, r, c);
    }
}

int bfs(int i, int j) {
    queue<pii> q1, q2;
    q1.push({i, j});
    visited[i][j] = 0;
    
    int n = matrix[i][j];
    
    while (!q1.empty()) {
        int y = q1.front().first;
        int x = q1.front().second;
        q1.pop();
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= N || c < 0 || c >= N) continue;
            if (matrix[r][c] == 0) {
                q2.push({y, x});
                continue;
            }
            if (matrix[r][c] != n) continue;
            if (visited[r][c] == 0) continue;
            visited[r][c] = 0;
            q1.push({r, c});
            
        }
    }
    
    while (!q2.empty()) {
        int y = q2.front().first;
        int x = q2.front().second;
        q2.pop();
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= N || c < 0 || c >= N) continue;
            if (matrix[r][c] != 0 && matrix[r][c] != n) return visited[y][x];
            if (matrix[r][c] != 0) continue;
            if (visited[r][c] <= visited[y][x] + 1) continue;
            visited[r][c] = visited[y][x] + 1;
            q2.push({r, c});
        }
    }
    return INF;
}
