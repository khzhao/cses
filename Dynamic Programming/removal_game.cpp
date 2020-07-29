#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>

#define ll long long
#define ar array
#define f(i,a,b) for (int i=a; i<b; i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int contents[n];
    f(i,0,n) cin >> contents[i];
    
    ll d[n][n];
    f(i,0,n) memset(&d[i], 0, sizeof(ll)*n);

    for (int i=n-1; i>=0; i--) {
        for (int j=i+1; j<n; j++) { 
            if (i==j) d[i][j]=contents[i];
            else {
                ll first=contents[i], second=contents[j];
                ll res_f=1e9+7, res_s=1e9+7;
                if (i+2<n) res_f=min(res_f, d[i+2][j]);
                if (i+1<n&&j-1>=0) {
                    res_f=min(res_f, d[i+1][j-1]);
                    res_s=min(res_s, d[i+1][j-1]);
                }                
                if (j-2>=0) res_s=min(res_s, d[i][j-2]);

                d[i][j]=max(first+res_f, second+res_s);
            }
        }
    }

    cout << d[0][n-1] << endl;

}
