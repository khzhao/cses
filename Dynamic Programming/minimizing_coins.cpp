#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

#define ll long long

using namespace std;

int main() {
    int n, money;
    cin >> n >> money;
    
    /*
    f(n) = 1 + min(f(c_1), f(c_2), .., f(c_n))   
    */

    ll f[money+1];
    f[0] = 0;
    
    vector<int> denoms_vec;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        denoms_vec.push_back(tmp);
    }

    for (int i=1; i<=money; i++) {
        ll ans=INT_MAX;
        for (auto coin : denoms_vec) {
            if (i-coin >= 0) ans=min(ans, f[i-coin]);
        }
        f[i]=1+ans; 
    }    

    if (f[money] >= INT_MAX) cout << -1 << endl;
    else cout << f[money] << endl;
}
