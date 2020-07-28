#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>

#define ll long long
#define ar array

using namespace std;

int main() {
    int modulo=1e9+7;
    int n, m;
    cin >> n >> m;

    int contents[n];
    for (int i=0; i<n; i++) cin >> contents[i];

    int f[n][m];
    for (int j=0; j<m; j++) {
        if (contents[0]) f[0][j]=(j+1==contents[0]);
        else f[0][j]=1;
    } 

    for (int i=1; i<n; i++) {
        if (contents[i]) {
            int j=contents[i]-1;
            int ans=f[i-1][j];
            if (j-1>=0) ans=(ans+f[i-1][j-1])%modulo;
            if (j+1<m) ans=(ans+f[i-1][j+1])%modulo;
            f[i][j]=ans;
            for (int k=0; k<m; k++)
                if (k!=j) 
                    f[i][k]=0;
        } else {
            for (int j=0; j<m; j++) {
                int ans=f[i-1][j];
                if (j-1>=0) ans=(ans+f[i-1][j-1])%modulo;
                if (j+1<m) ans=(ans+f[i-1][j+1])%modulo;
                f[i][j]=ans; 
            }
        }
    }
    
    int ans=0;
    for (int k=0; k<m; k++) {
        ans=(ans+f[n-1][k])%modulo;
    }
    cout << ans << endl;
}  
