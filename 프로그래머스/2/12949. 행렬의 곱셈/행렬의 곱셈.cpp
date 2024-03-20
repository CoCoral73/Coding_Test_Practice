#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int row = arr1.size(), col = arr2[0].size();
    for (int i = 0; i < row; i++) {
        vector<int> line;
        for (int j = 0; j < col; j++) {
            int value = 0;
            for (int k = 0; k < arr2.size(); k++) {
                value += arr1[i][k] * arr2[k][j];
            }
            line.emplace_back(value);
        }
        answer.emplace_back(line);
    }

    return answer;
}