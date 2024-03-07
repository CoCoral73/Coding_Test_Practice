#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int s = 1, e = 1, sum = 1;
    while (e <= n) {
        if (sum < n) {
            e++;
            sum += e;
        }
        else if (sum > n) {
            sum -= s;
            s++;
        }
        else {
            answer++;
            sum -= s;
            s++;
            e++;
            sum += e;
        }
    }
    return answer;
}