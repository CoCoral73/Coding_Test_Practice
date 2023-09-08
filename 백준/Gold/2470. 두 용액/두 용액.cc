#include <bits/stdc++.h>
using namespace std ;
class Best
{
public:
    int first ;
    int second ;
    int val ;
    Best(){ first = 0, second = 0, val = 2e31 - 2; }
};
int N ;
Best best = Best() ;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> N ;
    vector<int> liquid(N) ;

    for(int &it : liquid)
        cin >> it ;
    sort(liquid.begin(), liquid.end()) ;

    for(int i = 0 ; i < N - 1 ; i++)
    {
        int low = i + 1, high = N - 1 ;
        while(low != high)
        {
            int mid = (low + high) >> 1 ;
            int now = abs(liquid[i] + liquid[mid]) ;

            if(now > abs(liquid[i] + liquid[mid + 1]))
            {
                low = mid + 1 ;
            }
            else if(now > abs(liquid[i] + liquid[mid - 1]))
            {
                high = mid ;
            }
            else
            {
                low = mid ;
                break ;
            }
        }

        if(abs(best.val) > abs(liquid[i] + liquid[low]))
        {
            best.first = liquid[i] ;
            best.second = liquid[low] ;
            best.val = liquid[i] + liquid[low] ;
        }
    }

    cout << best.first << " " << best.second << "\n" ;
}