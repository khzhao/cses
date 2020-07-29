#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <queue>

#define ll long long
#define ar array
#define f(i,a,b) for (int i=a; i<b; i++)

using namespace std;

const int mxN=1e3, mxM=1e3;
int n, m;
string board[mxN];
bool vis[mxN][mxM];
char dir[mxN][mxM];
bool reachable=false;


bool e(int i, int j) {
    return !vis[i][j]&&i>=0&&i<n&&j>=0&&j<m&&(board[i][j]=='.'||board[i][j]=='B');
}

void bfs(int i, int j) {
    queue<ar<int,2>> q;
    q.push({i,j});
    
    while (!q.empty()) {
        auto el=q.front(); q.pop();
        int a=el[0], b=el[1];
        if (board[a][b]=='B') {
            reachable=true;
        }

        vis[a][b]=1;
        if (e(a+1, b)) dir[a+1][b]='D', q.push({a+1,b});
        if (e(a-1, b)) dir[a-1][b]='U', q.push({a-1,b});
        if (e(a, b+1)) dir[a][b+1]='R', q.push({a,b+1});
        if (e(a, b-1)) dir[a][b-1]='L', q.push({a,b-1});
    }
}

int main() {
    cin >> n >> m;
    f(i,0,n) cin >> board[i];

    int endi, endj;
    
    f(i,0,n) {
        f(j,0,m) {
            if (board[i][j]=='A') bfs(i, j);
            if (board[i][j]=='B') endi=i, endj=j;
        }
    }

    cout << (reachable?"YES":"NO") << endl;

    if (reachable) {
        string out;
        while (board[endi][endj]!='A') {
            char p=dir[endi][endj];
            out+=p;
            if(p=='D') endi--;
            if(p=='U') endi++;
            if(p=='L') endj++;
            if(p=='R') endj--;
        } 
        out+=dir[endi][endj];

        cout << out.size()-1 << endl;
        reverse(out.begin(), out.end());
        cout << out << endl;
    }
}
