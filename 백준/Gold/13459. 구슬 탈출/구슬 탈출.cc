#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Q13459 {
    int N, M;
    char **map;
    int rx, ry, bx, by;
    int MIN = 11;
public:
    Q13459();
    void bfs();
    int getMIN() { return MIN; }
};

Q13459::Q13459() {
    cin >> N >> M;
    map = new char*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new char[M];
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                rx = i, ry = j;
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B') {
                bx = i, by = j;
                map[i][j] = '.';
            }
        }
    }
}
void Q13459::bfs() {
    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> Q;
    Q.emplace(make_pair(make_pair(rx, ry), make_pair(bx, by)), 0);
    int tmp1, tmp2, flag1, flag2;

    while (!Q.empty()) {
        pair<int, int> red = Q.front().first.first;
        pair<int, int> blue = Q.front().first.second;
        int cnt = Q.front().second;
        //cout << red.first << ' ' << red.second << endl;
        //cout << blue.first << ' ' << blue.second << endl;
        //cout << cnt << endl << endl;
        Q.pop();

        if (red.first == blue.first) { //좌 우
            tmp1 = tmp2 = 0;
            flag1 = flag2 = 0;
            for (int i = red.first-1; i > 0; i--) {
                if (!flag1 && map[i][red.second] == 'O') {
                    MIN = min(MIN, cnt + 1);
                    goto NEXT1;
                }
                if (!flag2 && map[i][blue.second] == 'O')
                    goto NEXT1;
                if (map[i][red.second] == '#')
                    flag1 = 1;
                if (map[i][blue.second] == '#')
                    flag2 = 1;
                if (!flag1 && map[i][red.second] == '.')
                    tmp1++;
                if (!flag2 && map[i][blue.second] == '.')
                    tmp2++;
                if (flag1 && flag2)
                    break;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first-tmp1, red.second), make_pair(blue.first-tmp2, blue.second)), cnt+1);

            NEXT1:
            tmp1 = tmp2 = 0;
            flag1 = flag2 = 0;
            for (int i = red.first+1; i < N-1; i++) {
                if (!flag1 && map[i][red.second] == 'O') {
                    MIN = min(MIN, cnt+1);
                    goto NEXT2;
                }
                if (!flag2 && map[i][blue.second] == 'O')
                    goto NEXT2;
                if (map[i][red.second] == '#')
                    flag1 = 1;
                if (map[i][blue.second] == '#')
                    flag2 = 1;
                if (!flag1 && map[i][red.second] == '.')
                    tmp1++;
                if (!flag2 && map[i][blue.second] == '.')
                    tmp2++;
                if (flag1 && flag2)
                    break;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first+tmp1, red.second), make_pair(blue.first+tmp2, blue.second)), cnt+1);

            NEXT2:
            if (red.second < blue.second) {
                flag1 = flag2 = 0;
                tmp1 = tmp2 = 0;
                for (int i = red.second-1; i > 0; i--) {
                    if (map[red.first][i] == 'O') {
                        flag1 = 1;
                        tmp1 = 99999;
                        break;
                    }
                    if (map[red.first][i] == '#')
                        break;
                    if (map[red.first][i] == '.')
                        tmp1++;
                }
                for (int i = blue.second-1; i > 0; i--) {
                    if (map[blue.first][i] == 'O') {
                        flag2 = 1;
                        goto NEXT3;
                    }
                    if (map[blue.first][i] == '#' || i == red.second-tmp1)
                        break;
                    if (map[blue.first][i] == '.')
                        tmp2++;
                }
                if (flag1 && !flag2) {
                    MIN = min(MIN, cnt+1);
                    goto NEXT3;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first, red.second-tmp1), make_pair(blue.first, blue.second-tmp2)), cnt+1);

                NEXT3:
                tmp1 = tmp2 = 0;
                for (int i = blue.second+1; i < M-1; i++) {
                    if (map[blue.first][i] == 'O')
                        goto NEXT;
                    if (map[blue.first][i] == '#')
                        break;
                    if (map[blue.first][i] == '.')
                        tmp2++;
                }
                for (int i = red.second+1; i < M-1; i++) {
                    if (map[red.first][i] == 'O') {
                        MIN = min(MIN, cnt+1);
                        goto NEXT;
                    }
                    if (map[red.first][i] == '#' || i == blue.second+tmp2)
                        break;
                    if (map[red.first][i] == '.')
                        tmp1++;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first, red.second+tmp1), make_pair(blue.first, blue.second+tmp2)), cnt+1);
            }
            else { //red.second > blue.second
                tmp1 = tmp2 = 0;
                for (int i = blue.second-1; i > 0; i--) {
                    if (map[blue.first][i] == 'O')
                        goto NEXT4;
                    if (map[blue.first][i] == '#')
                        break;
                    if (map[blue.first][i] == '.')
                        tmp2++;
                }
                for (int i = red.second-1; i > 0; i--) {
                    if (map[red.first][i] == 'O') {
                        MIN = min(MIN, cnt+1);
                        goto NEXT4;
                    }
                    if (map[red.first][i] == '#' || i == blue.second-tmp2)
                        break;
                    if (map[red.first][i] == '.')
                        tmp1++;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first, red.second-tmp1), make_pair(blue.first, blue.second-tmp2)), cnt+1);

                NEXT4:
                flag1 = flag2 = 0;
                tmp1 = tmp2 = 0;
                for (int i = red.second+1; i < M-1; i++) {
                    if (map[red.first][i] == 'O') {
                        flag1 = 1;
                        tmp1 = 99999;
                        break;
                    }
                    if (map[red.first][i] == '#')
                        break;
                    if (map[red.first][i] == '.')
                        tmp1++;
                }
                for (int i = blue.second+1; i < M-1; i++) {
                    if (map[blue.first][i] == 'O') {
                        flag2 = 1;
                        goto NEXT;
                    }
                    if (map[blue.first][i] == '#' || i == red.second+tmp1)
                        break;
                    if (map[blue.first][i] == '.')
                        tmp2++;
                }
                if (flag1 && !flag2) {
                    MIN = min(MIN, cnt+1);
                    goto NEXT;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first, red.second+tmp1), make_pair(blue.first, blue.second+tmp2)), cnt+1);
            }
        }
        else if (red.second == blue.second) { //상 하
            if (red.first < blue.first) {
                flag1 = flag2 = 0;
                tmp1 = tmp2 = 0;
                for (int i = red.first-1; i > 0; i--) {
                    if (map[i][red.second] == 'O') {
                        flag1 = 1;
                        tmp1 = 99999;
                        break;
                    }
                    if (map[i][red.second] == '#')
                        break;
                    if (map[i][red.second] == '.')
                        tmp1++;
                }
                for (int i = blue.first-1; i > 0; i--) {
                    if (map[i][blue.second] == 'O') {
                        flag2 = 1;
                        goto NEXT5;
                    }
                    if (map[i][blue.second] == '#' || i == red.first-tmp1)
                        break;
                    if (map[i][blue.second] == '.')
                        tmp2++;
                }
                if (flag1 && !flag2) {
                    MIN = min(MIN, cnt+1);
                    goto NEXT5;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first-tmp1, red.second), make_pair(blue.first-tmp2, blue.second)), cnt+1);

                NEXT5:
                tmp1 = tmp2 = 0;
                for (int i = blue.first+1; i < N-1; i++) {
                    if (map[i][blue.second] == 'O')
                        goto NEXT6;
                    if (map[i][blue.second] == '#')
                        break;
                    if (map[i][blue.second] == '.')
                        tmp2++;
                }
                for (int i = red.first+1; i < N-1; i++) {
                    if (map[i][red.second] == 'O') {
                        MIN = min(MIN, cnt+1);
                        goto NEXT6;
                    }
                    if (map[i][red.second] == '#' || i == blue.first+tmp2)
                        break;
                    if (map[i][red.second] == '.')
                        tmp1++;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first+tmp1, red.second), make_pair(blue.first+tmp2, blue.second)), cnt+1);
            }
            else { //red.first > blue.first
                tmp1 = tmp2 = 0;
                for (int i = blue.first-1; i > 0; i--) {
                    if (map[i][blue.second] == 'O')
                        goto NEXT7;
                    if (map[i][blue.second] == '#')
                        break;
                    if (map[i][blue.second] == '.')
                        tmp2++;
                }
                for (int i = red.first-1; i > 0; i--) {
                    if (map[i][red.second] == 'O') {
                        MIN = min(MIN, cnt+1);
                        goto NEXT7;
                    }
                    if (map[i][red.second] == '#' || i == blue.first-tmp2)
                        break;
                    if (map[i][red.second] == '.')
                        tmp1++;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first-tmp1, red.second), make_pair(blue.first-tmp2, blue.second)), cnt+1);

                NEXT7:
                flag1 = flag2 = 0;
                tmp1 = tmp2 = 0;
                for (int i = red.first+1; i < N-1; i++) {
                    if (map[i][red.second] == 'O') {
                        flag1 = 1;
                        tmp1 = 99999;
                        break;
                    }
                    if (map[i][red.second] == '#')
                        break;
                    if (map[i][red.second] == '.')
                        tmp1++;
                }
                for (int i = blue.first+1; i < N-1; i++) {
                    if (map[i][blue.second] == 'O') {
                        flag2 = 1;
                        goto NEXT6;
                    }
                    if (map[i][blue.second] == '#' || i == red.first+tmp1)
                        break;
                    if (map[i][blue.second] == '.')
                        tmp2++;
                }
                if (flag1 && !flag2) {
                    MIN = min(MIN, cnt+1);
                    goto NEXT6;
                }
                if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                    Q.emplace(make_pair(make_pair(red.first+tmp1, red.second), make_pair(blue.first+tmp2, blue.second)), cnt+1);
            }
            NEXT6:
            tmp1 = tmp2 = 0;
            flag1 = flag2 = 0;
            for (int i = red.second-1; i > 0; i--) {
                if (!flag1 && map[red.first][i] == 'O') {
                    MIN = min(MIN, cnt+1);
                    goto NEXT8;
                }
                if (!flag2 && map[blue.first][i] == 'O')
                    goto NEXT8;
                if (map[red.first][i] == '#')
                    flag1 = 1;
                if (map[blue.first][i] == '#')
                    flag2 = 1;
                if (!flag1 && map[red.first][i] == '.')
                    tmp1++;
                if (!flag2 && map[blue.first][i] == '.')
                    tmp2++;
                if (flag1 && flag2)
                    break;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first, red.second-tmp1), make_pair(blue.first, blue.second-tmp2)), cnt+1);

            NEXT8:
            tmp1 = tmp2 = 0;
            flag1 = flag2 = 0;
            for (int i = red.second+1; i < M-1; i++) {
                if (!flag1 && map[red.first][i] == 'O') {
                    MIN = min(MIN, cnt+1);
                    goto NEXT;
                }
                if (!flag2 && map[blue.first][i] == 'O')
                    goto NEXT;
                if (map[red.first][i] == '#')
                    flag1 = 1;
                if (map[blue.first][i] == '#')
                    flag2 = 1;
                if (!flag1 && map[red.first][i] == '.')
                    tmp1++;
                if (!flag2 && map[blue.first][i] == '.')
                    tmp2++;
                if (flag1 && flag2)
                    break;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first, red.second+tmp1), make_pair(blue.first, blue.second+tmp2)), cnt+1);
        }
        else {
            tmp1 = tmp2 = 0;
            for (int i = red.first-1; i > 0; i--) {
                if (map[i][red.second] == 'O') {
                    MIN = min(MIN, cnt+1);
                    goto NEXT9;
                }
                if (map[i][red.second] == '#')
                    break;
                if (map[i][red.second] == '.')
                    tmp1++;
            }
            for (int i = blue.first-1; i > 0; i--) {
                if (map[i][blue.second] == 'O')
                    goto NEXT9;
                if (map[i][blue.second] == '#')
                    break;
                if (map[i][blue.second] == '.')
                    tmp2++;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first-tmp1, red.second), make_pair(blue.first-tmp2, blue.second)), cnt+1);

            NEXT9:
            tmp1 = tmp2 = 0;
            for (int i = red.first+1; i < N-1; i++) {
                if (map[i][red.second] == 'O') {
                    MIN = min(MIN, cnt + 1);
                    goto NEXT10;
                }
                if (map[i][red.second] == '#')
                    break;
                if (map[i][red.second] == '.')
                    tmp1++;
            }
            for (int i = blue.first+1; i < N-1; i++) {
                if (map[i][blue.second] == 'O')
                    goto NEXT10;
                if (map[i][blue.second] == '#')
                    break;
                if (map[i][blue.second] == '.')
                    tmp2++;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first+tmp1, red.second), make_pair(blue.first+tmp2, blue.second)), cnt+1);

            NEXT10:
            tmp1 = tmp2 = 0;
            for (int i = red.second-1; i > 0; i--) {
                if (map[red.first][i] == 'O') {
                    MIN = min(MIN, cnt+1);
                    goto NEXT11;
                }
                if (map[red.first][i] == '#')
                    break;
                if (map[red.first][i] == '.')
                    tmp1++;
            }
            for (int i = blue.second-1; i > 0; i--) {
                if (map[blue.first][i] == 'O')
                    goto NEXT11;
                if (map[blue.first][i] == '#')
                    break;
                if (map[blue.first][i] == '.')
                    tmp2++;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first, red.second-tmp1), make_pair(blue.first, blue.second-tmp2)), cnt+1);

            NEXT11:
            tmp1 = tmp2 = 0;
            for (int i = red.second+1; i < M-1; i++) {
                if (map[red.first][i] == 'O') {
                    MIN = min(MIN, cnt+1);
                    goto NEXT;
                }
                if (map[red.first][i] == '#')
                    break;
                if (map[red.first][i] == '.')
                    tmp1++;
            }
            for (int i = blue.second+1; i < M-1; i++) {
                if (map[blue.first][i] == 'O')
                    goto NEXT;
                if (map[blue.first][i] == '#')
                    break;
                if (map[blue.first][i] == '.')
                    tmp2++;
            }
            if ((tmp1 != 0 || tmp2 != 0) && cnt+1 <= 10)
                Q.emplace(make_pair(make_pair(red.first, red.second+tmp1), make_pair(blue.first, blue.second+tmp2)), cnt+1);
        }
        NEXT:
        continue;
    }
}

int main() {
    Q13459 Q;
    Q.bfs();
    int rst = Q.getMIN();
    if (rst <= 10)
        cout << 1;
    else
        cout << 0;
}