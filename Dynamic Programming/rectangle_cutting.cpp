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
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    int f[a][b];
    for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) { 
            if (i==j) f[i][j]=0;
            if (i==0 || j==0) {
                f[i][j]=max(i,j);
            } else {
                // Dimension of rectangle is
                // (i+1) by (j+1)
                
                int ans=INT_MAX;
                f(k,0,j) ans=min(ans,f[i][j-k]+f[i][k]);
                f(k,0,i) ans=min(ans,f[i-k][j]+f[k][j]);
                f[i][j]=1+ans;
            }
        }
    }

    cout << f[a-1][b-1] << endl;
}
