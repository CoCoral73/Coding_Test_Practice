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

int n;
int matrix[100][100];
bool isVisited[100][100];
int MAX = 0;
int answer = 0;

int bfs(int h);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            MAX = max(MAX, matrix[i][j]);
        }
    }
    
    for (int i = 0; i < MAX; i++) {
        answer = max(answer, bfs(i));
    }
    
    cout << answer;
    
}

int bfs(int h) {
    fill((bool *)isVisited, (bool *)isVisited + 100 * 100, 0);
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > h && !isVisited[i][j]) {
                answer++;
                
                queue<pii> q;
                q.emplace(i, j);
                isVisited[i][j] = true;
                
                while (!q.empty()) {
                    pii front = q.front();
                    q.pop();
                    
                    for (int i = 0; i < 4; i++) {
                        int r = front.first + dr[i];
                        int c = front.second + dc[i];
                        
                        if (r < 0 || r >= n || c < 0 || c >= n) continue;
                        if (matrix[r][c] <= h || isVisited[r][c]) continue;
                        
                        isVisited[r][c] = true;
                        q.emplace(r, c);
                    }
                }
            }
        }
    }
    return answer;
}
