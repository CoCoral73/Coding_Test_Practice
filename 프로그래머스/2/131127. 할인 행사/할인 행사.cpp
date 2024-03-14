#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> index;
    for (int i = 0; i < want.size(); i++)
        index[want[i]] = i;

    for (int i = 0; i <= discount.size()-10; i++) {
        vector<int> nums = vector<int>(number.size());
        for (int j = i; j < i + 10 && j < discount.size(); j++) {
            if (index.find(discount[j]) == index.end()) break;
            nums[index[discount[j]]]++;
        }

        bool flag = true;
        for (int j = 0; j < number.size(); j++) {
            if (number[j] != nums[j]) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}