#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

typedef struct node {
    vector<string> user;    //나를 신고한 사용자
    int count;      //결과값
    node() {
        vector<string> v;
        this->user = v;
        count = 0;
    }
}NODE;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, NODE> count;
    for (int i = 0; i < id_list.size(); i++)
        count.insert({id_list[i], node()});

    set<string> S;
    for (int i = 0; i < report.size(); i++) {
        if (S.find(report[i]) != S.end())
            continue;
        S.insert(report[i]);
        stringstream str(report[i]);
        string ing, ed;
        str >> ing >> ed;
        count[ed].user.emplace_back(ing);
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        if (count[id_list[i]].user.size() < k)
            continue;
        for (int j = 0; j < count[id_list[i]].user.size(); j++) {
            string name = count[id_list[i]].user[j];
            count[name].count++;
        }
    }
    
    for (int i = 0; i < id_list.size(); i++)
        answer.emplace_back(count[id_list[i]].count);
    return answer;
}