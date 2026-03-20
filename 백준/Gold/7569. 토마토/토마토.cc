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
int dr[6] = {-1, 0, 1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int M, N, H;
int tomato[100][100][100];
int isVisited[100][100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N >> H;
    
    int total = M * N * H;
    int answer = 0;
    
    queue<pair<int, pii>> q;
    fill(&isVisited[0][0][0], &isVisited[0][0][0] + 100 * 100 * 100, INF);
    
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> tomato[h][n][m];
                
                if (tomato[h][n][m] == 1) {
                    q.push({h, {n, m}});
                    isVisited[h][n][m] = 0;
                    total -= 1;
                } else if (tomato[h][n][m] == -1) {
                    total -= 1;
                }
            }
        }
    }
    
    while (!q.empty()) {
        pair<int, pii> front = q.front();
        q.pop();
        
        if (total == 0) {
            cout << answer;
            return 0;
        }
        
        for (int i = 0; i < 6; i++) {
            int h = front.first + dh[i];
            int r = front.second.first + dr[i];
            int c = front.second.second + dc[i];
            
            if (h < 0 || h >= H || r < 0 || r >= N || c < 0 || c >= M) continue;
            if (tomato[h][r][c] != 0) continue;
            if (isVisited[h][r][c] <= isVisited[front.first][front.second.first][front.second.second] + 1) continue;
            
            isVisited[h][r][c] = isVisited[front.first][front.second.first][front.second.second] + 1;
            answer = max(answer, isVisited[h][r][c]);
            total -= 1;
            q.push({h, {r, c}});
        }
    }
    
    cout << -1;
}
