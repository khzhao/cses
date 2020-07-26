#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    ll modulo=1e9+7;
    ll ans = 1;
    
    for (int i=1; i <= n; i++) {
        ans += ans;
        ans %= modulo;
    }

    cout << ans << endl;
}
