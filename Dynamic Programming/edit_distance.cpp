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
    string s, t;
    cin >> s >> t;

    if (s.size()<t.size()) s.swap(t);

    int n=s.size(), m=t.size();
    ll d[n+1][m+1];

    f(k,0,m+1) d[0][k]=k;
    f(k,0,n+1) d[k][0]=k;

    for (int j=1; j<m+1; j++) {
        for (int i=1; i<n+1; i++) {
            ll ans=INT_MAX;
            if (s[i-1]==t[j-1]) ans=d[i-1][j-1];
            ans=min({
                ans,
                d[i-1][j]+1,
                d[i][j-1]+1,
                d[i-1][j-1]+1
            }); 
            d[i][j]=ans;
         }
    }

    cout << d[n][m] << endl; 
}
