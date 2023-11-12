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

class BJ {
    char cube[6][3][3];
    char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
public:
    BJ();
    void initCube();
    void rotateUp(bool isPlus);
    void rotateDown(bool isPlus);
    void rotateFront(bool isPlus);
    void rotateBack(bool isPlus);
    void rotateLeft(bool isPlus);
    void rotateRight(bool isPlus);
};

BJ::BJ() {
    int T, n;
    char ch1, ch2;

    cin >> T;
    while (T--) {
        cin >> n;
        initCube();
        while (n--) {
            cin >> ch1 >> ch2;
            switch (ch1) {
                case 'U': rotateUp(ch2 == '+'); break;
                case 'D': rotateDown(ch2 == '+'); break;
                case 'F': rotateFront(ch2 == '+'); break;
                case 'B': rotateBack(ch2 == '+'); break;
                case 'L': rotateLeft(ch2 == '+'); break;
                default: rotateRight(ch2 == '+'); break;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << cube[0][i][j];
            cout << '\n';
        }
    }
}
void BJ::initCube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cube[i][j][k] = color[i];
    }
}
void BJ::rotateUp(bool isPlus) {
    // front(2), back(3), left(4), right(5)
    char tmp[3] = {cube[3][0][0], cube[3][0][1], cube[3][0][2]};
    char up[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            up[i][j] = cube[0][i][j];

    if (isPlus) {
        for (int i = 0; i < 3; i++)
            cube[3][0][i] = cube[4][0][i];
        for (int i = 0; i < 3; i++)
            cube[4][0][i] = cube[2][0][i];
        for (int i = 0; i < 3; i++)
            cube[2][0][i] = cube[5][0][i];
        for (int i = 0; i < 3; i++)
            cube[5][0][i] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[0][i][j] = up[2-j][i];
    }
    else {
        for (int i = 0; i < 3; i++)
            cube[3][0][i] = cube[5][0][i];
        for (int i = 0; i < 3; i++)
            cube[5][0][i] = cube[2][0][i];
        for (int i = 0; i < 3; i++)
            cube[2][0][i] = cube[4][0][i];
        for (int i = 0; i < 3; i++)
            cube[4][0][i] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[0][i][j] = up[j][2-i];
    }
}
void BJ::rotateDown(bool isPlus) {
    // front(2) back(3) left(4) right(5)
    char tmp[3] = {cube[2][2][0], cube[2][2][1], cube[2][2][2]};
    char down[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            down[i][j] = cube[1][i][j];

    if (isPlus) {
        for (int i = 0; i < 3; i++)
            cube[2][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++)
            cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++)
            cube[3][2][i] = cube[5][2][i];
        for (int i = 0; i < 3; i++)
            cube[5][2][i] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[1][i][j] = down[2-j][i];
    }
    else {
        for (int i = 0; i < 3; i++)
            cube[2][2][i] = cube[5][2][i];
        for (int i = 0; i < 3; i++)
            cube[5][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++)
            cube[3][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++)
            cube[4][2][i] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[1][i][j] = down[j][2-i];
    }
}
void BJ::rotateFront(bool isPlus) {
    // up(0), down(1), left(4), right(5)
    char tmp[3] = {cube[0][2][0], cube[0][2][1], cube[0][2][2]};
    char front[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            front[i][j] = cube[2][i][j];

    if (isPlus) {
        for (int i = 0; i < 3; i++)
            cube[0][2][i] = cube[4][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[4][2-i][2] = cube[1][0][2-i];
        for (int i = 0; i < 3; i++)
            cube[1][0][2-i] = cube[5][i][0];
        for (int i = 0; i < 3; i++)
            cube[5][i][0] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[2][i][j] = front[2-j][i];
    }
    else {
        for (int i = 0; i < 3; i++)
            cube[0][2][i] = cube[5][i][0];
        for (int i = 0; i < 3; i++)
            cube[5][i][0] = cube[1][0][2-i];
        for (int i = 0; i < 3; i++)
            cube[1][0][2-i] = cube[4][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[4][2-i][2] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[2][i][j] = front[j][2-i];
    }
}
void BJ::rotateBack(bool isPlus) {
    // up(0), down(1), left(4), right(5)
    char tmp[3] = {cube[0][0][2], cube[0][0][1], cube[0][0][0]};
    char back[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            back[i][j] = cube[3][i][j];

    if (isPlus) {
        for (int i = 0; i < 3; i++)
            cube[0][0][2-i] = cube[5][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[5][2-i][2] = cube[1][2][i];
        for (int i = 0; i < 3; i++)
            cube[1][2][i] = cube[4][i][0];
        for (int i = 0; i < 3; i++)
            cube[4][i][0] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[3][i][j] = back[2-j][i];
    }
    else {
        for (int i = 0; i < 3; i++)
            cube[0][0][2-i] = cube[4][i][0];
        for (int i = 0; i < 3; i++)
            cube[4][i][0] = cube[1][2][i];
        for (int i = 0; i < 3; i++)
            cube[1][2][i] = cube[5][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[5][2-i][2] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[3][i][j] = back[j][2-i];
    }
}
void BJ::rotateLeft(bool isPlus) {
    // up(0), down(1), front(2), back(3)
    char tmp[3] = {cube[0][0][0], cube[0][1][0], cube[0][2][0]};
    char left[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            left[i][j] = cube[4][i][j];

    if (isPlus) {
        for (int i = 0; i < 3; i++)
            cube[0][i][0] = cube[3][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[3][2-i][2] = cube[1][i][0];
        for (int i = 0; i < 3; i++)
            cube[1][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++)
            cube[2][i][0] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[4][i][j] = left[2-j][i];
    }
    else {
        for (int i = 0; i < 3; i++)
            cube[0][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++)
            cube[2][i][0] = cube[1][i][0];
        for (int i = 0; i < 3; i++)
            cube[1][i][0] = cube[3][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[3][2-i][2] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[4][i][j] = left[j][2-i];
    }
}
void BJ::rotateRight(bool isPlus) {
    // up(0), down(1), front(2), back(3)
    char tmp[3] = {cube[0][2][2], cube[0][1][2], cube[0][0][2]};
    char right[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            right[i][j] = cube[5][i][j];

    if (isPlus) {
        for (int i = 0; i < 3; i++)
            cube[0][2-i][2] = cube[2][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[2][2-i][2] = cube[1][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[1][2-i][2] = cube[3][i][0];
        for (int i = 0; i < 3; i++)
            cube[3][i][0] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[5][i][j] = right[2-j][i];
    }
    else {
        for (int i = 0; i < 3; i++)
            cube[0][2-i][2] = cube[3][i][0];
        for (int i = 0; i < 3; i++)
            cube[3][i][0] = cube[1][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[1][2-i][2] = cube[2][2-i][2];
        for (int i = 0; i < 3; i++)
            cube[2][2-i][2] = tmp[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[5][i][j] = right[j][2-i];
    }
}

signed main() {
    fastIO;

    BJ Q5373;
}