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

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<ll> contents(n);
    up(i,0,n) cin >> contents[i];

    ll prev=contents[0];
    ll max_sum=prev;
    up(i,1,n) {
        prev=max(prev+contents[i], contents[i]);
        max_sum=max(max_sum, prev);
    }

    cout << max_sum << endl;
        

}
