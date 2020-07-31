#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>

#define ll long long
#define ar array
#define rep(i,a,b) for(int i=a; i<b; i++)
#define repd(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int contents[n];
    rep(i,0,n) cin >> contents[i];
    
    ll f[n][n];
    rep(i,0,n) memset(&f[i], 0, sizeof(ll)*n);
    
    repd(i,n-1,-1) {
        rep(j,0,n) {
            if (i==j) {
                f[i][j]=contents[i];
            } else if (i+1==j) {
                f[i][j]=max(contents[i], contents[j]);
            } else {
                if (i>j) continue;
                ll first=contents[i], second=contents[j];
                ll res_f=1e12+7, res_s=1e12+7;
                if (i+2<=j) res_f=min(res_f, f[i+2][j]);
                if (j-2>=i) res_s=min(res_s, f[i][j-2]);
                if (i+1<=j-1) {
                    res_f=min(res_f, f[i+1][j-1]);
                    res_s=min(res_s, f[i+1][j-1]);
                }
                f[i][j]=max(first+res_f,second+res_s);
            }
        }
    }

    cout << f[0][n-1] << endl;
}
