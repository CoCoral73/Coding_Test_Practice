#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    pair<string, int> type[4] = {{"RT", 0}, {"CF", 0}, {"JM", 0}, {"AN", 0}};
    for (int i = 0; i < survey.size(); i++) {
        int flag = -1;
        if (survey[i][0] > survey[i][1])
            flag = 1;
        if (survey[i] == "RT" || survey[i] == "TR")
            type[0].second += (choices[i]-4)*flag;
        else if (survey[i] == "CF" || survey[i] == "FC")
            type[1].second += (choices[i]-4)*flag;
        else if (survey[i] == "JM" || survey[i] == "MJ")
            type[2].second += (choices[i]-4)*flag;
        else
            type[3].second += (choices[i]-4)*flag;
    }

    for (int i = 0; i < 4; i++) {
        if (type[i].second >= 0)
            answer += type[i].first[0];
        else
            answer += type[i].first[1];
    }
    return answer;
}