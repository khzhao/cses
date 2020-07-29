#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>

#define ll long long
#define ar array
#define f(i,n,m) for (int i=n; i<m; i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[n];
    f(i,0,n) cin >> coins[i];
    sort(coins, coins+n);

    int total=0;
    f(i,0,n) total+=coins[i];

    int prev[total+1];
    f(i,0,total+1) prev[i]=(i==0);

    for (auto coin: coins) {
        int now[total+1];
        f(k,0,total+1) {
            int ans=prev[k];
            if (k-coin>=0) ans+=prev[k-coin];
            now[k]=ans;
        }
        memcpy(prev,now,sizeof(int)*(total+1));
    }        

    int res=0;
    vector<int> results;
    f(k,0,total+1)
        if (k&&prev[k]) {
            res++;
            results.push_back(k);
        } 

    cout << res << endl;
    for (auto el: results) cout << el << " ";
}
