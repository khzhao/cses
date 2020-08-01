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
#include <set>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    set<ar<int,3>> s;

    up(i,0,4) {
        int n;
        cin >> n;
        s.insert({n, i});
    }

    for (auto el: s) {
        cout << el[0] << " " << el[1] << endl;
    }


}
