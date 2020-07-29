#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <numeric>
#include <vector>
#include <climits>
#include <cstring>

#define ll long long
#define ar array
#define f(i,a,b) for (int i=a; i<b; i++)

using namespace std;

int main() {    
    string board[8];
    f(i,0,8) cin >> board[i];
    
    int pos[8], ans=0;
    iota(pos, pos+8, 0);
    
    do {
        bool ok=1;
        f(i,0,8) {
            ok&=(board[i][pos[i]]=='.');
        }
        
        // Make sure nothing is on the same diagonal
        bool diag[15];
        memset(diag, 0, 15);
        f(i,0,8) {
            if (diag[i+pos[i]]) ok=0;
            diag[i+pos[i]]=1;
        }

        memset(diag, 0, 15);
        f(i,0,8) {
            if (diag[7+i-pos[i]]) ok=0;
            diag[7+i-pos[i]]=1;
        }
        
        ans+=ok;
    } while (next_permutation(pos, pos+8));    
    
    cout << ans << endl;
}
