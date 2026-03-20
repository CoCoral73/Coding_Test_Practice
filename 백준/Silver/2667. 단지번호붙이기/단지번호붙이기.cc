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
vector<string> matrix;
int isVisited[25][25];
vector<int> v;

void bfs(int i, int j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        matrix.emplace_back(str);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1' && !isVisited[i][j])
                bfs(i, j);
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto x : v)
        cout << x << '\n';
}

void bfs(int i, int j) {
    queue<pii> q;
    q.emplace(i, j);
    isVisited[i][j] = true;
    
    int result = 0;
    while (!q.empty()) {
        pii front = q.front();
        q.pop();
        
        result++;
        
        for (int i = 0; i < 4; i++) {
            int r = front.first + dr[i];
            int c = front.second + dc[i];
            
            if (r < 0 || r >= n || c < 0 || c >= n) continue;
            if (matrix[r][c] == '0' || isVisited[r][c]) continue;
            isVisited[r][c] = true;
            q.emplace(r, c);
        }
    }
    
    v.emplace_back(result);
}
