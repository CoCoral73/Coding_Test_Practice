#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int MIN = 0, MAX = *max_element(citations.begin(), citations.end());
    int mid;
    while (MIN <= MAX) {
        mid = (MIN + MAX) / 2;
        int count = 0;
        for (int c : citations) {
            if (c >= mid) count++;
        }
        if (count >= mid && citations.size() - count <= mid) {
            answer = mid;
            MIN = mid + 1;
        }
        else MAX = mid - 1;
    }

    return answer;
}