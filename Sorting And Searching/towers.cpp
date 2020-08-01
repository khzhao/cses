#include <bits/stdc++.h>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cubes(n);
    up(i,0,n) cin >> cubes[i];
    
    vector<int> towers;

    for (int cube: cubes) {
        auto it=upper_bound(towers.begin(), towers.end(), cube);
        if (it==towers.end()) {
            towers.pb(cube);
        } else {
            if (*it==cube) {
                towers.pb(cube);
            } else {
                *it=cube;
            }
        }
    }

    cout << towers.size() << endl;
}
