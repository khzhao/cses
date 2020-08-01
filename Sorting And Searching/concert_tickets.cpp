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
    int n, m;
    cin >> n >> m;

    set<ar<int,2>> prices;
    up(i,0,n) {
        int price;
        cin >> price;
        prices.insert({price,i});
    }

    vector<int> max_price(m);
    up(i,0,m) cin >> max_price[i];

    for (int mp: max_price) {
        auto it=prices.lower_bound({mp+1,0}); 
        if (it==prices.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            cout << (*it)[0] << endl;
            prices.erase(it);
        }
    }
}
