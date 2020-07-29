#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>

#define ll long long
#define ar array
#define f(i,a,b) for (int i=a; i<b; i++)

using namespace std;

const int mxN=1e3, mxM=1e3;
int n, m;
string board[mxN];

bool e(int i, int j) {
    return i>=0&&j>=0&&i<n&&j<m&&board[i][j]=='.';
}

void dfs(int i, int j) {
    board[i][j]='#';
    if (e(i+1, j)) dfs(i+1, j);
    if (e(i-1, j)) dfs(i-1, j);
    if (e(i, j+1)) dfs(i, j+1);
    if (e(i, j-1)) dfs(i, j-1);
}

int main() {
    cin >> n >> m;
    f(i,0,n) cin >> board[i];

    int ans=0;
    f(i,0,n) {
        f(j,0,m) {
            if (e(i,j)) dfs(i,j), ans++;
        }
    }

    cout << ans << endl;
}
