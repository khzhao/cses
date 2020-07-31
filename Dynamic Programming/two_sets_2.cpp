// C Libraries
#include <climits>
#include <cstring>
#include <cstdio>

// C++ Libraries
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>n; i--)
#define pb push_back

using namespace std;

const int mod=1e9+7;

int main() {
    ll n;
    cin >> n;
    
    if (n%4!=0&&n%4!=3) {
        cout << 0 << endl; return 0;
    }
    
    ll sum=n*(n+1)/4;
    ll prev[sum+1];
    memset(prev,0,sizeof(ll)*(sum+1));
    prev[0]=1,prev[1]=1;

    up(j,1,n) {
        ll now[sum+1];
        up(i,0,sum+1) {
            now[i]=prev[i];
            ll coin=j+1;
            if (i-coin>=0) now[i]=(now[i]+prev[i-coin])%mod;
        }
        memcpy(prev,now,(sum+1)*sizeof(ll));
    }
    
    cout << prev[sum]*((mod+1)/2)%mod << endl;
}



