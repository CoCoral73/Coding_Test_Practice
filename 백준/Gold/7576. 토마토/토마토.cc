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
int box[1000][1000];
int visited[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N;
    
    fill((int *)visited, (int *)visited + 1000*1000, INF);
    
    queue<pii> q;
    int tomato = M*N;
    int answer = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            
            if (box[i][j] == 1) {
                q.emplace(i, j);
                visited[i][j] = 0;
                tomato -= 1;
            } else if (box[i][j] == -1) {
                tomato -= 1;
            }
        }
    }
    
    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();
        
        if (tomato == 0) {
            cout << answer;
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int y = r + dr[i];
            int x = c + dc[i];
            
            if (y < 0 || y >= N || x < 0 || x >= M) { continue; }
            if (box[y][x] != 0 || visited[y][x] <= visited[r][c] + 1) { continue; }
            
            visited[y][x] = visited[r][c] + 1;
            answer = max(answer, visited[y][x]);
            tomato -= 1;
            q.emplace(y, x);
        }
    }
    
    cout << -1;
    
}
