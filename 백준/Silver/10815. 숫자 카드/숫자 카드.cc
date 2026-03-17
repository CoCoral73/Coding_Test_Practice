//
//  main.cpp
//  CppPractice
//
//  Created by 김정원 on 3/13/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N, M, card;
vector<int> cards;

bool binarySearch(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> card;
        cards.emplace_back(card);
    }
    
    sort(cards.begin(), cards.end());
    
    cin >> M;
    while (M--) {
        cin >> card;
        cout << binarySearch(card) << ' ';
    }
}

bool binarySearch(int x) {
    int left = 0, right = N-1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (x < cards[mid]) {
            right = mid - 1;
        } else if (x > cards[mid]) {
            left = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}
