#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

class BJ {
    int R, C;
    string *maze;
    int sr, sc;
    queue<pair<int, int>> fire;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int **visited;
    bool **Vf;
    int avail = 0;
public:
    BJ();
    void bfs();
};

BJ::BJ() {
    cin >> R >> C;
    maze = new string[R];
    visited = new int*[R];
    Vf = new bool*[R];
    for (int i = 0; i < R; i++) {
        cin >> maze[i];
        visited[i] = new int[C];
        Vf[i] = new bool[C];
        for (int j = 0; j < C; j++) {
            visited[i][j] = INT32_MAX;
            Vf[i][j] = false;
            if (maze[i][j] == 'J')
                sr = i, sc = j;
            if (maze[i][j] == 'F') {
                fire.emplace(i, j);
                Vf[i][j] = true;
            }
            if ((maze[i][j] == 'J' || maze[i][j] == '.') && (i == 0 || i == R-1 || j == 0 || j == C-1))
                avail++;
        }
    }
}
void BJ::bfs() {
    if (sr == 0 || sr == R-1 || sc == 0 || sc == C-1) {
        cout << 1;
        return;
    }
    visited[sr][sc] = 1;
    queue<pair<int, int>> Q;
    Q.emplace(sr, sc);

    int fsize = fire.size();
    int qsize = Q.size();
    while (true) {
        while (fsize > 0) {
            int fr = fire.front().first;
            int fc = fire.front().second;
            fire.pop();
            fsize--;
            for (int i = 0; i < 4; i++) {
                int FR = fr + dr[i];
                int FC = fc + dc[i];
                if (FR < 0 || FR >= R || FC < 0 || FC >= C)
                    continue;
                if (maze[FR][FC] == '#')
                    continue;
                if (!Vf[FR][FC]) {
                    Vf[FR][FC] = true;
                    if (FR == 0 || FR == R-1 || FC == 0 || FC == C-1)
                        avail--;
                    maze[FR][FC] = 'F';
                    fire.emplace(FR, FC);
                }
            }
        }
        if (avail <= 0)
            break;
        while (qsize > 0) {
            int r = Q.front().first;
            int c = Q.front().second;
            Q.pop();
            qsize--;
            for (int i = 0; i < 4; i++) {
                int jr = r + dr[i];
                int jc = c + dc[i];
                if (jr < 0 || jr >= R || jc < 0 || jc >= C)
                    continue;
                if (maze[jr][jc] == '#' || maze[jr][jc] == 'F')
                    continue;
                if (visited[jr][jc] > visited[r][c] + 1) {
                    visited[jr][jc] = visited[r][c] + 1;
                    if (jr == 0 || jr == R-1 || jc == 0 || jc == C-1) {
                        cout << visited[jr][jc];
                        return;
                    }
                    Q.emplace(jr, jc);
                }
            }
        }

        if (Q.empty())
            break;
        fsize = fire.size();
        qsize = Q.size();
    }

    cout << "IMPOSSIBLE";
}

int main() {
    fastIO;
    BJ a;
    a.bfs();
}