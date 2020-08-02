#include <bits/stdc++.h>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<ll> times(n);
    up(i,0,n) cin >> times[i];

    ll left=1;
    ll right=1e18;
    while (left<right) {
        ll _products=0;
        ll mid=(right+left)/2;
        for (auto machine: times) {
            _products+=min(mid/machine, (ll)1e12);
        }

        if (_products>=t) {
            right=mid;
        } else {
            left=mid+1;
        }
    }
    cout << left << endl;
}
