#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct date {
    int year;
    int month;
    int day;
}DATE;

bool isValid(DATE today, DATE privacy) {
    if (privacy.year < today.year)
        return true;
    if (privacy.year > today.year)
        return false;
    if (privacy.month < today.month)
        return true;
    if (privacy.month > today.month)
        return false;
    if (privacy.day < today.day)
        return true;
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    DATE Today = {stoi(today.substr(0, 4)), stoi(today.substr(5, 2)), stoi(today.substr(8, 2))};
    map<char, int> types;
    for (int i = 0; i < terms.size(); i++)
        types.insert({terms[i][0], atoi(&terms[i][2])});
    vector<int> answer;
    for (int i = 0; i < privacies.size(); i++) {
        int p_year = stoi(privacies[i].substr(0, 4));
        int p_month = stoi(privacies[i].substr(5, 2));
        int p_day = stoi(privacies[i].substr(8, 2));
        char type = privacies[i][11];
        p_month += types[type];
        p_year += (p_month-1) / 12;
        p_month -= (p_month-1)/12*12;
        p_day--;
        if (p_day < 1) {
            p_day = 28;
            p_month--;
            if (p_month < 1) {
                p_month = 12;
                p_year--;
            }
        }
        if (isValid(Today, {p_year, p_month, p_day}))
            answer.emplace_back(i+1);
    }
    return answer;
}