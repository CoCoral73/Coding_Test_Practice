#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a%b);
}

signed main() {
    fastIO;

    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    int lcm = 4*w*h / GCD(2*w, 2*h);
    t = t % lcm;

    int dw = 1, dh = 1;
    while (true) {
        int mw = dw == 1 ? w - p : p;
        int mh = dh == 1 ? h - q : q;
        if (min(mw, mh) <= t) {
            p += dw * min(mw, mh);
            q += dh * min(mw, mh);
            if (p == 0 || p == w)
                dw *= -1;
            if (q == 0 || q == h)
                dh *= -1;
            t -= min(mw, mh);
        }
        else {
            p += dw * t;
            q += dh * t;
            break;
        }
    }
    cout << p << ' ' << q;
}