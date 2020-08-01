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
#include <queue>
#include <set>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    int n;
    cin >> n;

    set<ar<int,2>> times;
    up(i,0,n) {
        int a, b;
        cin >> a >> b;
        times.insert({a, 1});
        times.insert({b, -1});
    }
    
    int sum=0;
    int ans=0;
    for (auto el: times) {
        sum+=el[1];
        ans=max(ans,sum);
    }
    
    cout << ans << endl;
}
