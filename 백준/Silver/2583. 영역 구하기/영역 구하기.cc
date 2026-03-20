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

int m, n, k;
int paper[100][100];
int isVisited[100][100];
vector<int> v;

void bfs(int i, int j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n >> k;
    
    int x1, y1, x2, y2;
    while (k--) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                paper[i][j] = 1;
            }
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (paper[i][j] == 0 && !isVisited[i][j]) {
                bfs(i, j);
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto x: v) {
        cout << x << ' ';
    }
}

void bfs(int i, int j) {
    queue<pii> q;
    q.emplace(i, j);
    isVisited[i][j] = true;
    
    int area = 0;
    while (!q.empty()) {
        pii front = q.front();
        q.pop();
        
        area++;
        for (int i = 0; i < 4; i++) {
            int r = front.first + dr[i];
            int c = front.second + dc[i];
            
            if (r < 0 || r >= m || c < 0 || c >= n) continue;
            if (paper[r][c] == 1 || isVisited[r][c]) continue;
            
            isVisited[r][c] = true;
            q.emplace(r, c);
        }
    }
    
    v.emplace_back(area);
}
