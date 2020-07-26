#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;

    ll modulo=1e9+7;
    ll throws[n+1];
    throws[0] = 1;

    for (int i=1; i<=n; i++) {
        ll ans=0;
        for (int j=1; j<=min(i, 6); j++) {
            ans = (ans + throws[i-j]) % modulo;
        }
        throws[i] = ans;
    }

    cout << throws[n] << endl;
}
