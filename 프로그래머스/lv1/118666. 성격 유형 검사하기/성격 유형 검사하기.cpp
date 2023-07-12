#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    pair<pair<char, char>, int> type[4] = {{{'R', 'T'}, 0}, {{'C', 'F'}, 0},
                                           {{'J', 'M'}, 0}, {{'A', 'N'}, 0}};
    int score[8] = {0,3,2,1,0,-1,-2,-3};
    for (int i = 0; i < survey.size(); i++) {
        int flag = 1;
        if (survey[i][0] > survey[i][1])
            flag = -1;
        if (survey[i] == "RT" || survey[i] == "TR")
            type[0].second += score[choices[i]]*flag;
        else if (survey[i] == "CF" || survey[i] == "FC")
            type[1].second += score[choices[i]]*flag;
        else if (survey[i] == "JM" || survey[i] == "MJ")
            type[2].second += score[choices[i]]*flag;
        else
            type[3].second += score[choices[i]]*flag;
    }

    for (int i = 0; i < 4; i++) {
        if (type[i].second >= 0)
            answer += type[i].first.first;
        else
            answer += type[i].first.second;
    }
    return answer;
}