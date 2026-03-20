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

int t, w, h;
vector<string> v;
int isVisited[1000][1000];
int isVisitedFire[1000][1000];

queue<pii> q1, q2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while (t--) {
        fill(&isVisited[0][0], &isVisited[0][0] + 1000 * 1000, INF);
        fill(&isVisitedFire[0][0], &isVisitedFire[0][0] + 1000 * 1000, INF);
        
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            string str;
            cin >> str;
            v.emplace_back(str);
            
            for (int j = 0; j < w; j++) {
                if (str[j] == '*') {
                    q1.emplace(i, j);
                    isVisitedFire[i][j] = 1;
                } else if (str[j] == '@') {
                    q2.emplace(i, j);
                    isVisited[i][j] = 1;
                }
            }
        }
        
        while (!q1.empty()) {
            pii front = q1.front();
            q1.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = front.first + dr[i];
                int c = front.second + dc[i];
                
                if (r < 0 || r >= h || c < 0 || c >= w) continue;
                if (v[r][c] == '#') continue;
                if (isVisitedFire[r][c] <= isVisitedFire[front.first][front.second] + 1) continue;
                
                isVisitedFire[r][c] = isVisitedFire[front.first][front.second] + 1;
                q1.emplace(r, c);
            }
        }
        
        bool flag = false;
        while (!q2.empty()) {
            pii front = q2.front();
            q2.pop();
            
            if (front.first == 0 || front.first == h-1 || front.second == 0 || front.second == w-1) {
                flag = true;
                cout << isVisited[front.first][front.second] << '\n';
                break;
            }
            
            for (int i = 0; i < 4; i++) {
                int r = front.first + dr[i];
                int c = front.second + dc[i];
                
                if (r < 0 || r >= h || c < 0 || c >= w) continue;
                if (v[r][c] == '#') continue;
                if (isVisited[r][c] <= isVisited[front.first][front.second] + 1) continue;
                if (isVisited[front.first][front.second] + 1 >= isVisitedFire[r][c]) continue;
                
                isVisited[r][c] = isVisited[front.first][front.second] + 1;
                q2.emplace(r, c);
            }
        }
        
        if (!flag) {
            cout << "IMPOSSIBLE\n";
        }
        
        v.clear();
        q2 = queue<pii>();
    }
}
