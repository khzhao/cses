#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    int f[n+1];
    f[0]=0;
    for (int i=1; i<n+1; i++) f[i]=INT_MAX;
    
    for (int i=1; i<=n; i++) {
        string s = to_string(i);
        
        for (char c : s) {
            if (c-48>0) f[i]=min(f[i], f[i-(c-48)]);    
        }
        f[i]++;
    }

    cout << f[n] << endl;
}
