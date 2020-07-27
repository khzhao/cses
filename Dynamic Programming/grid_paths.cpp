#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    string board[n];
    int modulo=1e9+7;
    for (int i=0; i<n; i++) {
        cin >> board[i];
    }
    
    int f[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bool ind1 = (i-1>=0 && board[i-1][j] != '*');
            bool ind2 = (j-1>=0 && board[i][j-1] != '*');
            f[i][j] = (ind1*f[i-1][j]+ind2*f[i][j-1])%modulo;
            if (i==0 && j==0) f[i][j]=1;
            if (board[i][j] == '*') f[i][j]=0;
        }
    }

    cout << f[n-1][n-1] << endl;
}
