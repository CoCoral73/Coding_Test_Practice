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
vector<string> grid;
int isVisited[100][100];

void bfs(bool isBlind, int i, int j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        grid.push_back(str);
    }
    
    int answer1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isVisited[i][j]) continue;
            
            bfs(false, i, j);
            answer1++;
        }
    }
    
    int answer2 = 0;
    fill((int *)isVisited, (int *)isVisited + 100 * 100, 0);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isVisited[i][j]) continue;
            
            bfs(true, i, j);
            answer2++;
        }
    }
    
    cout << answer1 << ' ' << answer2;
}

void bfs(bool isBlind, int i, int j) {
    queue<pii> q;
    q.emplace(i, j);
    
    int r, c;
    while (!q.empty()) {
        tie(r, c) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int y = r + dr[i];
            int x = c + dc[i];
            
            if (y < 0 || y >= N || x < 0 || x >= N) continue;
            if (isVisited[y][x]) continue;
            
            if (isBlind) {
                if ((grid[r][c] == 'R' && grid[y][x] == 'G') || (grid[r][c] == 'G' && grid[y][x] == 'R')) {
                    isVisited[y][x] = true;
                    q.emplace(y, x);
                } else if (grid[r][c] == grid[y][x]) {
                    isVisited[y][x] = true;
                    q.emplace(y, x);
                }
            } else {
                if (grid[r][c] != grid[y][x]) continue;
                
                isVisited[y][x] = true;
                q.emplace(y, x);
            }
        }
    }
}
