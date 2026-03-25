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
int ice[300][300];
int melting[300][300];
bool isVisited[300][300];
int cnt, answer;

int solution(int i, int j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ice[i][j];
            if (ice[i][j] != 0) {
                cnt++;
            }
        }
    }
    
    while (true) {
        fill(&isVisited[0][0], &isVisited[0][0] + 300 * 300, false);
        fill(&melting[0][0], &melting[0][0] + 300 * 300, 0);
        
        for  (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (ice[i][j] != 0 && !isVisited[i][j]) {
                    int result = solution(i, j);
                    if (cnt != result) {
                        cout << answer+1;
                        return 0;
                    } else {
                        goto next;
                    }
                }
            }
        }
        
        next:
        answer++;
        
        if (cnt == 0) {
            cout << 0;
            return 0;
        }
    }
}

int solution(int i, int j) {
    queue<pii> q;
    q.push({i, j});
    isVisited[i][j] = true;
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= N || c < 0 || c >= M) continue;
            if (ice[r][c] == 0) {
                melting[y][x]++;
            } else {
                if (isVisited[r][c]) continue;
                isVisited[r][c] = true;
                q.push({r, c});
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ice[i][j] > 0) {
                ice[i][j] -= min(ice[i][j], melting[i][j]);
                if (ice[i][j] == 0) {
                    cnt--;
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ice[i][j] == 0 || !isVisited[i][j]) continue;
            q.push({i, j});
            isVisited[i][j] = false;
            int result = 0;
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                result++;
                
                for (int k = 0; k < 4; k++) {
                    int r = y + dr[k];
                    int c = x + dc[k];
                    
                    if (r < 0 || r >= N || c < 0 || c >= M) continue;
                    if (ice[r][c] == 0 || !isVisited[r][c]) continue;
                    isVisited[r][c] = false;
                    q.push({r, c});
                }
            }
            return result;
        }
    }
    
    return 0;
}
