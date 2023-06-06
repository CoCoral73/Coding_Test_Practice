#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct node {
    int next;
    bool isTeam;
    int visit;
    int indexInVector;
}NODE;

vector<int> connect;
int v_idx;

void dfs(NODE* member, int start) {
    if (member[start].isTeam || member[start].visit == 2)
        return;
    if (member[start].visit == 1) {
        v_idx = member[start].indexInVector;
        return;
    }
    connect.emplace_back(start);
    member[start].indexInVector = connect.size()-1;
    member[start].visit = 1;
    dfs(member, member[start].next);
    if (member[start].indexInVector >= v_idx)
        member[start].isTeam = true;
    else
        member[start].visit = 2;
}

int main() {
    fastIO;

    int T, n, num;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;
        NODE *member = new NODE[n];
        for (int j = 0; j < n; j++) {
            cin >> num;
            member[j] = {num-1, false, 0};
        }

        int answer = 0;
        for (int j = 0; j < n; j++) {
            connect.clear();
            v_idx = INT32_MAX;
            dfs(member, j);
            if (!member[j].isTeam)
                answer++;
            //cout << j+1 << ' ' << member[j].isTeam << endl;
        }
        cout << answer << '\n';

        delete[] member;
    }
}