#include <bits/stdc++.h>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    vector<int> lights(n);
    up(i,0,n) cin >> lights[i];

    set<int> pos;
    pos.insert(0);
    pos.insert(x);

    map<int,int> mp;
    mp[x]=1;

    for (int light: lights) {
        auto bot=pos.lower_bound(light);
        int r=*bot;
        bot--;
        int l=*bot;

        mp[r-l]--;
        if (!mp[r-l]) mp.erase(r-l);

        pos.insert(light);
        
        mp[r-light]++;
        mp[light-l]++;

        cout << (--mp.end())->first << " ";
    }
    cout << '\n';
}
