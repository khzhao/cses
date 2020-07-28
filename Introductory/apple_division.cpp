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
    int n;
    cin >> n;

    int apples[n];
    ll total_weight=0;
    for (int i=0; i<n; i++) {
        cin >> apples[i];
        total_weight+=apples[i];
    }
    
    ll ans=0;
    for (int i=0; i<1<<n; i++) {
        ll cs=0;
        for (int j=0; j<n; j++) {
            if ((i>>j)&1) cs+=apples[j];
        }
        if (cs<=total_weight/2) ans=max(ans,cs);
    }

    cout << total_weight-2*ans << endl;

}
