#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int i = 0;
    while (i < progresses.size()) {
        int progress = progresses[i], speed = speeds[i];
        int days = (100 - progress) / speed;
        if (progress + days * speed < 100) days++;

        int count = 1, j = i + 1;
        while (j < progresses.size()) {
            if (progresses[j] + days * speeds[j] < 100) break;
            count++;
            j++;
        }
        answer.emplace_back(count);
        i = j;
    }
    return answer;
}