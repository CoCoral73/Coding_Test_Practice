#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> stack;

    for (int i = 0; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        stack.clear();
        for (int j = 0; j < s.size(); j++) {
            if (stack.empty()) stack.emplace_back(s[j]);
            else if (stack.back() == '(' && s[j] == ')') stack.pop_back();
            else if (stack.back() == '{' && s[j] == '}') stack.pop_back();
            else if (stack.back() == '[' && s[j] == ']') stack.pop_back();
            else stack.emplace_back(s[j]);
        }
        if (stack.empty())
            answer++;
    }
    return answer;
}