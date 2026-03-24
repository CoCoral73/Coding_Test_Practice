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
vector<string> matrix;
int isVisited[2][1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(&isVisited[0][0][0], &isVisited[0][0][0] + 2*1000*1000, INF);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        matrix.emplace_back(str);
    }
    
    queue<pair<bool, pii>> q;
    q.push({false, {0, 0}});
    isVisited[0][0][0] = 1;
    
    while (!q.empty()) {
        bool isBreak = q.front().first;
        pii rc = q.front().second;
        q.pop();
        
        if (rc.first == N-1 && rc.second == M-1) {
            cout << min(isVisited[0][rc.first][rc.second], isVisited[1][rc.first][rc.second]);
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int r = rc.first + dr[i];
            int c = rc.second + dc[i];
            
            if (r < 0 || r >= N || c < 0 || c >= M) continue;
            if (matrix[r][c] == '0') {
                if (isVisited[isBreak][r][c] > isVisited[isBreak][rc.first][rc.second] + 1) {
                    isVisited[isBreak][r][c] = isVisited[isBreak][rc.first][rc.second] + 1;
                    q.push({isBreak, {r, c}});
                }
            } else {
                if (isBreak) continue;
                if (isVisited[true][r][c] > isVisited[0][rc.first][rc.second] + 1) {
                    isVisited[true][r][c] = isVisited[0][rc.first][rc.second] + 1;
                    q.push({true, {r, c}});
                }
            }
        }
        
    }
    
    cout << -1;
}
