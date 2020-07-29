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
    int d[a+1][b+1]; 

    f(i,1,a+1) {
        f(j,1,b+1) {
             if (i==j) {
                d[i][j]=0;
             } else {
                int ans=1e9;
                f(k,1,j) ans=min(ans,d[i][k]+d[i][j-k]);
                f(k,1,i) ans=min(ans,d[k][j]+d[i-k][j]);
                d[i][j]=ans+1;
             }
        }
    }

    cout << d[a][b] << endl;
}
