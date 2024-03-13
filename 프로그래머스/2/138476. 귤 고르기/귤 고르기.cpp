#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    vector<int> count;
    
    for (int i = 0; i < tangerine.size(); ) {
        int j = i+1, cnt = 1;
        while (tangerine[i] == tangerine[j]) {
            cnt++;
            j++;
        }
        count.emplace_back(cnt);
        i = j;
    }
    sort(count.begin(), count.end());
    for (int i = count.size()-1; i >= 0; i--) {
        answer++;
        k -= count[i];
        if (k <= 0) break;
    }
    return answer;
}