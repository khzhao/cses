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
    int n, m;
    cin >> n >> m;
    
    int modulo=1e9+7;
    int contents[n];
    for (int i=0; i<n; i++) {
        cin >> contents[i];
    }
    
    // f(n,m): number of arrays of size n
    // but ending in m
    int f[n][m];
    for (int i=0; i<m; i++) f[0][i]=1;

    for (int i=1; i<n; i++) {
        for (int j=0; j<m; j++) {
            int ans=f[i-1][j];
            if (j+1<m) ans=(ans+f[i-1][j+1])%modulo;
            if (j-1>=0) ans=(ans+f[i-1][j-1])%modulo;
            f[i][j]=ans;
        }
    }
    
    // Iterate through contents
    int point=0;
    int num_arrays=0;
    

}  
