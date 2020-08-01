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
    int n, x;
    cin >> n >> x;

    set<ar<int,2>> vals;
    up(i,0,n) {
        int val;
        cin >> val;
        vals.insert({val, i+1});
    }

    for (auto el: vals) {
        auto it=vals.lower_bound({x-el[0]});
        if (it!=vals.end()&&(*it)[1]!=el[1]&&(*it)[0]+el[0]==x) {
            cout << el[1] << " " << (*it)[1] << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    

}
