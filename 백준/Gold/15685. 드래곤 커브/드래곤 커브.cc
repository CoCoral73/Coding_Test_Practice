#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <memory.h>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class BJ{
    int N;
    bool grid[101][101];
public:
    BJ();
    int countSquare();
};

BJ::BJ() {
    cin >> N;

    memset(grid, 0, sizeof(bool)*101*101);
    int x, y, d, g;
    while (N--) {
        cin >> x >> y >> d >> g;
        vector<pair<int, int>> points;
        points.emplace_back(y, x);
        grid[y][x] = true;
        switch (d) {
            case 0: x++; break;
            case 1: y--; break;
            case 2: x--; break;
            default: y++; break;
        }
        grid[y][x] = true;
        points.emplace_back(y, x);

        for (int i = 1; i <= g; i++) {
            pair<int, int> end_point = points.back();
            for (int j = points.size() - 1; j >= 0; j--) {
                tie(y, x) = points[j];
                int X = abs(x - end_point.second);
                int Y = abs(y - end_point.first);
                if (x >= end_point.second && y >= end_point.first) {
                    grid[end_point.first + X][end_point.second - Y] = true;
                    points.emplace_back(end_point.first + X, end_point.second - Y);
                }
                else if (y >= end_point.first) {
                    grid[end_point.first - X][end_point.second - Y] = true;
                    points.emplace_back(end_point.first - X, end_point.second - Y);
                }
                else if (x >= end_point.second) {
                    grid[end_point.first + X][end_point.second + Y] = true;
                    points.emplace_back(end_point.first + X, end_point.second + Y);
                }
                else {
                    grid[end_point.first - X][end_point.second + Y] = true;
                    points.emplace_back(end_point.first - X, end_point.second + Y);
                }
            }
        }
    }
    cout << countSquare();
}
int BJ::countSquare() {
    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1])
                answer++;
        }
    }
    return answer;
}

signed main() {
    fastIO;

    BJ Q15685;
}