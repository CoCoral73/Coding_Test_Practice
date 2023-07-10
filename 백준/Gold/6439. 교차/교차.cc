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

int main() {
    int T;
    int lx1, ly1, lx2, ly2;
    int rx1, ry1, rx2, ry2;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> lx1 >> ly1 >> lx2 >> ly2;
        pair<int, int> l1 = make_pair(lx1, ly1);
        pair<int, int> l2 = make_pair(lx2, ly2);
        cin >> rx1 >> ry1 >> rx2 >> ry2;
        pair<int, int> r1, r2, r3, r4;
        if (rx1 < rx2) {
            if (ry1 < ry2) {
                r1 = make_pair(rx1, ry1);
                r2 = make_pair(rx1, ry2);
                r3 = make_pair(rx2, ry2);
                r4 = make_pair(rx2, ry1);
            }
            else {
                r1 = make_pair(rx1, ry2);
                r2 = make_pair(rx1, ry1);
                r3 = make_pair(rx2, ry1);
                r4 = make_pair(rx2, ry2);
            }
        }
        else {
            if (ry1 < ry2) {
                r1 = make_pair(rx2, ry1);
                r2 = make_pair(rx2, ry2);
                r3 = make_pair(rx1, ry2);
                r4 = make_pair(rx1, ry1);
            }
            else {
                r1 = make_pair(rx2, ry2);
                r2 = make_pair(rx2, ry1);
                r3 = make_pair(rx1, ry1);
                r4 = make_pair(rx1, ry2);
            }
        }

        if (ccw(l1,l2,r1)*ccw(l1,l2,r2) <= 0 && ccw(r1,r2,l1)*ccw(r1,r2,l2) <= 0) {
            if (ccw(l1,l2,r1) == 0 && ccw(l1,l2,r2) == 0) {
                if (l1.second < r1.second && l2.second < r1.second || l1.second > r2.second && l2.second > r2.second)
                    cout << "F" << endl;
                else
                    cout << "T" << endl;
            }
            else
                cout << "T" << endl;
        }
        else if (ccw(l1,l2,r2)*ccw(l1,l2,r3) <= 0 && ccw(r2,r3,l1)*ccw(r2,r3,l2) <= 0) {
            if (ccw(l1,l2,r2) == 0 && ccw(l1,l2,r3) == 0) {
                if (l1.first < r2.first && l2.first < r2.first || l1.first > r3.first && l2.first > r3.first)
                    cout << "F" << endl;
                else
                    cout << "T" << endl;
            }
            else
                cout << "T" << endl;
        }
        else if (ccw(l1,l2,r3)*ccw(l1,l2,r4) <= 0 && ccw(r3,r4,l1)*ccw(r3,r4,l2) <= 0) {
            if (ccw(l1,l2,r3) == 0 && ccw(l1,l2,r4) == 0) {
                if (l1.second < r4.second && l2.second < r4.second || l1.second > r3.second && l2.second > r3.second)
                    cout << "F" << endl;
                else
                    cout << "T" << endl;
            }
            else
                cout << "T" << endl;
        }
        else if (ccw(l1,l2,r4)*ccw(l1,l2,r1) <= 0 && ccw(r4,r1,l1)*ccw(r4,r1,l2) <= 0) {
            if (ccw(l1,l2,r4) == 0 && ccw(l1,l2,r1) == 0) {
                if (l1.first < r1.first && l2.first < r1.first || l1.first > r4.first && l2.first > r4.first)
                    cout << "F" << endl;
                else
                    cout << "T" << endl;
            }
            else
                cout << "T" << endl;
        }
        else if (r1.first <= l1.first && l1.first <= r4.first && r1.second <= l1.second && l1.second <= r2.second)
            cout << "T" << endl;
        else if (r1.first <= l2.first && l2.first <= r4.first && r1.second <= l2.second && l2.second <= r2.second)
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
}