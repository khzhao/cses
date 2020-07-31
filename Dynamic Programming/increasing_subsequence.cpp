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

    vector<int> contents(n);
    up(i,0,n) cin >> contents[i];

    vector<int> f;
    up(i,0,n) {
        auto it=lower_bound(f.begin(), f.end(), contents[i]);
        if (it==f.end()) f.pb(contents[i]);
        else {
            *it=contents[i];
        }
    }

    cout << f.size() << endl;
}
