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

class BJ {
    int n;
    vector<int> inorder;
    vector<int> postorder;
    vector<int> preorder;
    int last = 0;
public:
    BJ();
    void solution(int root, pair<int, int> in, pair<int, int> post);
};

BJ::BJ() {
    cin >> n;
    inorder = vector<int>(n);
    for (int &x : inorder)
        cin >> x;
    postorder = vector<int>(n);
    for (int &x : postorder)
        cin >> x;
    preorder = vector<int>(n);

    solution(postorder.back(), {0, n-1}, {0, n-1});
    for (int x : preorder)
        cout << x << ' ';
}
void BJ::solution(int root, pair<int, int> in, pair<int, int> post) {
    preorder[last++] = root;
    if (in.first >= in.second || post.first >= post.second)
        return;

    int in_index = -1;
    for (int i = in.first; i <= in.second; i++) {
        if (inorder[i] == root) {
            in_index = i;
            break;
        }
    }
    int left = in_index - in.first, right = in.second - in_index;
    int left_root = post.first + left - 1, right_root = post.second - 1;
    //cout << postorder[left_root] << ' ' << postorder[right_root] << endl;
    if (left > 0)
        solution(postorder[left_root], {in.first, in_index - 1}, {post.first, post.first + left - 1});
    if (right > 0)
        solution(postorder[right_root], {in_index + 1, in.second}, {post.first + left, post.second - 1});
}

signed main() {
    fastIO;

    BJ Q2263;
}