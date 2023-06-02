#include <iostream>
#include <utility>
using namespace std;

int ccw(pair<int, int> d1, pair<int, int> d2, pair<int, int> d3) {
    int rst = d1.first*d2.second+d2.first*d3.second+d3.first*d1.second;
    rst -= (d2.first*d1.second+d3.first*d2.second+d1.first*d3.second);
    if (rst > 0)
        return 1;
    else if (rst == 0)
        return 0;
    return -1;
}

int solve(pair<int, int> r1, pair<int, int> r2, pair<int, int> r3, pair<int, int> r4, pair<int, int> d1, pair<int, int> d2) {
    int ccw1, ccw2, rst = 0, flag = 0;
    if (ccw(r1,r2,d1)*ccw(r1,r2,d2) <= 0 && ccw(d1,d2,r1)*ccw(d1,d2,r2) <= 0) {
        ccw1 = ccw(r1,r2,d1);
        ccw2 = ccw(r1,r2,d2);
        if (ccw1 == 0 && ccw2 == 0) {
            if (d1.second < r1.second && d2.second < r1.second || d1.second > r2.second && d2.second > r2.second)
                return 0;
            if (d1.second < r1.second && d2.second == r1.second || d2.second < r1.second && d1.second == r1.second)
                return 1;
            if (d1.second > r2.second && d2.second == r2.second || d2.second > r2.second && d1.second == r2.second)
                return 1;
            return 4;
        }
        if (ccw1*ccw2 < 0 && ccw(d1,d2,r1)*ccw(d1,d2,r2) < 0)
            rst++;
        else {
            rst++;
        }
    }
    if (ccw(r2,r3,d1)*ccw(r2,r3,d2) <= 0 && ccw(d1,d2,r2)*ccw(d1,d2,r3) <= 0) {
        ccw1 = ccw(r2, r3, d1);
        ccw2 = ccw(r2, r3, d2);
        if (ccw1 == 0 && ccw2 == 0) {
            if (d1.first < r2.first && d2.first < r2.first || d1.first > r3.first && d2.first > r3.first)
                return 0;
            if (d1.first < r2.first && d2.first == r2.first || d2.first < r2.first && d1.first == r2.first)
                return 1;
            if (d1.first > r3.first && d2.first == r3.first || d2.first > r3.first && d1.first == r3.first)
                return 1;
            return 4;
        }
        if (ccw1*ccw2 < 0 && ccw(d1,d2,r2)*ccw(d1,d2,r3) < 0)
            rst++;
        else {
            if (ccw(d1,d2,r2) != 0)
                rst++;
        }
    }
    if (ccw(r3,r4,d1)*ccw(r3,r4,d2) <= 0 && ccw(d1,d2,r3)*ccw(d1,d2,r4) <= 0) {
        ccw1 = ccw(r3, r4, d1);
        ccw2 = ccw(r3, r4, d2);
        if (ccw1 == 0 && ccw2 == 0) {
            if (d1.second < r4.second && d2.second < r4.second || d1.second > r3.second && d2.second > r3.second)
                return 0;
            if (d1.second < r4.second && d2.second == r4.second || d2.second < r4.second && d1.second == r4.second)
                return 1;
            if (d1.second > r3.second && d2.second == r3.second || d2.second > r3.second && d1.second == r3.second)
                return 1;
            return 4;
        }
        if (ccw1*ccw2 < 0 && ccw(d1,d2,r3)*ccw(d1,d2,r4) < 0)
            rst++;
        else {
            if (ccw(d1,d2,r3) != 0)
                rst++;
        }
    }
    if (ccw(r4,r1,d1)*ccw(r4,r1,d2) <= 0 && ccw(d1,d2,r4)*ccw(d1,d2,r1) <= 0) {
        ccw1 = ccw(r4, r1, d1);
        ccw2 = ccw(r4, r1, d2);
        if (ccw1 == 0 && ccw2 == 0) {
            if (d1.first < r1.first && d2.first < r1.first || d1.first > r4.first && d2.first > r4.first)
                return 0;
            if (d1.first < r1.first && d2.first == r1.first || d2.first < r1.first && d1.first == r1.first)
                return 1;
            if (d1.first > r4.first && d2.first == r4.first || d2.first > r4.first && d1.first == r4.first)
                return 1;
            return 4;
        }
        if (ccw1*ccw2 < 0 && ccw(d1,d2,r4)*ccw(d1,d2,r1) < 0)
            rst++;
        else {
            if (ccw(d1,d2,r4) != 0 && ccw(d1,d2,r1) != 0)
                rst++;
        }
    }
    return rst;
}

int main() {
    int T, x1, y1, x2, y2;
    cin >> T;
    for (int i = 0; i < T; i++) {
        pair<int, int> r1, r2, r3, r4;
        cin >> x1 >> y1 >> x2 >> y2;
        r1 = make_pair(x1, y1);
        r2 = make_pair(x1, y2);
        r3 = make_pair(x2, y2);
        r4 = make_pair(x2, y1);
        pair<int, int> d1, d2;
        cin >> x1 >> y1 >> x2 >> y2;
        d1 = make_pair(x1, y1);
        d2 = make_pair(x2, y2);

        cout << solve(r1,r2,r3,r4,d1,d2) << '\n';
    }
}