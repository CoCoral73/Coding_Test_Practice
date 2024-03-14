#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> sums;
    int size = elements.size();

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < i + size; j++) {
            sum += elements[j % size];
            sums.emplace(sum);
        }
    }

    return sums.size();
}