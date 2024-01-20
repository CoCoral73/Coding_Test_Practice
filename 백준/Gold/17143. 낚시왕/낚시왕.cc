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

typedef struct node {
    int r, c;
    int s, d, z;
    bool isLive;
    node(int r, int c, int s, int d, int z) {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
        isLive = true;
    }
} NODE;

class BJ {
    int R, C, M;
    int king = 0;
    vector<NODE> sharks;
    int grid[150][150];
    int answer = 0;
public:
    BJ();
    void solution();
    void init();
};

BJ::BJ() {
    cin >> R >> C >> M;
    init();

    int r, c, s, d, z;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        sharks.emplace_back(r, c, s, d, z);
        grid[r][c] = i;
    }

    solution();
    cout << answer;
}
void BJ::solution() {
    while (king + 1 <= C) {
        king++;
        int r = 1;
        while (r <= R && grid[r][king] == -1) r++;
        if (r <= R) {
            int index = grid[r][king];
            answer += sharks[index].z;
            sharks[index].isLive = false;
        }

        init();
        for (int i = 0; i < M; i++) {
            if (!sharks[i].isLive) continue;
            int newR = sharks[i].r, newC = sharks[i].c;
            if (sharks[i].d <= 2) {
                int x = sharks[i].s % ((R-1)*2);
                newR += sharks[i].d == 1 ? -x : x;
                if (newR <= 0) {
                    newR = 2 - newR;
                    sharks[i].d = 2;
                    if (newR > R) {
                        newR = 2*R - newR;
                        sharks[i].d = 1;
                    }
                }
                if (newR > R) {
                    newR = 2*R - newR;
                    sharks[i].d = 1;
                    if (newR <= 0) {
                        newR = 2 - newR;
                        sharks[i].d = 2;
                    }
                }
                sharks[i].r = newR;
            }
            else {
                int x = sharks[i].s % ((C-1)*2);
                newC += sharks[i].d == 3 ? x : -x;
                if (newC <= 0) {
                    newC = 2 - newC;
                    sharks[i].d = 3;
                    if (newC > C) {
                        newC = 2*C - newC;
                        sharks[i].d = 4;
                    }
                }
                if (newC > C) {
                    newC = 2*C - newC;
                    sharks[i].d = 4;
                    if (newC <= 0) {
                        newC = 2 - newC;
                        sharks[i].d = 3;
                    }
                }
                sharks[i].c = newC;
            }

            if (grid[newR][newC] == -1)
                grid[newR][newC] = i;
            else {
                if (sharks[grid[newR][newC]].z < sharks[i].z) {
                    sharks[grid[newR][newC]].isLive = false;
                    grid[newR][newC] = i;
                }
                else {
                    sharks[i].isLive = false;
                }
            }
        }
        /*
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++)
                cout << grid[i][j] << '\t';
            cout << endl;
        }
        cout << endl;
        */
    }
}
void BJ::init() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
            grid[i][j] = -1;
    }
}

signed main() {
    BJ Q17143;
}