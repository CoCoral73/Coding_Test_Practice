#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <memory.h>
#define int long long
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ {
    int T;
    int h, w;
    char grid[100][100];
    bool visited[100][100];
    string keys;
    bool haveKey[26];
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int answer;
public:
    BJ();
    void initGrid();
    vector<pii> sideCheck();
    int solution();
};

BJ::BJ() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < 26; i++) haveKey[i] = false;
        answer = 0;
        
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                    if (islower(grid[i][j])) {
                        haveKey[grid[i][j]-'a'] = true;
                        grid[i][j] = '.';
                    }
                    else if (grid[i][j] == '$') {
                        answer++;
                        grid[i][j] = '.';
                    }
                }
            }
        }
        cin >> keys;
        if (keys != "0")
            for (int i = 0; i < keys.size(); i++) haveKey[keys[i]-'a'] = true;
        cout << solution() << '\n';
    }
}
void BJ::initGrid() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            visited[i][j] = false;
    }
}
vector<pii> BJ::sideCheck() {
    vector<pii> v;
    for (int i = 0; i < h; i++) {
        if (isupper(grid[i][0]) && haveKey[grid[i][0]-'A'])
            grid[i][0] = '.';
        if (isupper(grid[i][w-1]) && haveKey[grid[i][w-1]-'A'])
            grid[i][w-1] = '.';

        if (grid[i][0] == '.') {
            v.emplace_back(i, 0);
            visited[i][0] = true;
        }
        if (grid[i][w-1] == '.') {
            v.emplace_back(i, w - 1);
            visited[i][w-1] = true;
        }
    }

    for (int i = 1; i < w-1; i++) {
        if (isupper(grid[0][i]) && haveKey[grid[0][i]-'A'])
            grid[0][i] = '.';
        if (isupper(grid[h-1][i]) && haveKey[grid[h-1][i]-'A'])
            grid[h-1][i] = '.';

        if (grid[0][i] == '.') {
            v.emplace_back(0, i);
            visited[0][i] = true;
        }
        if (grid[h-1][i] == '.') {
            v.emplace_back(h - 1, i);
            visited[h-1][i] = true;
        }
    }
    return v;
}
int BJ::solution() {
    vector<pii> start;
    queue<pii> Q;

    initGrid();
    start = sideCheck();

    for (pii p : start) Q.emplace(p);

    while (!Q.empty()) {
        pii front = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int r = front.first + dr[i];
            int c = front.second + dc[i];
            if (r < 0 || r >= h || c < 0 || c >= w) continue;
            if (visited[r][c] || grid[r][c] == '*') continue;

            if (grid[r][c] == '$') {
                answer++;
                grid[r][c] = '.';
                visited[r][c] = true;
                Q.emplace(r, c);
            }
            else if (islower(grid[r][c])) {
                haveKey[grid[r][c]-'a'] = true;
                grid[r][c] = '.';
                initGrid();
                start = sideCheck();
                for (pii p : start) Q.emplace(p);
            }
            else if (isupper(grid[r][c])) {
                if (haveKey[grid[r][c]-'A']) {
                    grid[r][c] = '.';
                    visited[r][c] = true;
                    Q.emplace(r, c);
                }
            }
            else if (grid[r][c] == '.') {
                visited[r][c] = true;
                Q.emplace(r, c);
            }
        }
    }
    return answer;
}

signed main(){
    fastIO;

    BJ Q9328;
}
