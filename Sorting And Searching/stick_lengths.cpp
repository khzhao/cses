// C Libraries
#include <climits>
#include <cstring>
#include <cstdio>

// C++ Libraries
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<ll> sticks(n);
    up(i,0,n) cin >> sticks[i];

    sort(sticks.begin(), sticks.end());
    ll mid=sticks[sticks.size()/2-1];
    ll mid2=sticks[sticks.size()/2];

    ll distance=0, distance1=0;
    for (auto stick: sticks) {
        distance+=abs(stick-mid);
        distance1+=abs(stick-mid2);
    }

    cout << min(distance, distance1) << endl;
}
