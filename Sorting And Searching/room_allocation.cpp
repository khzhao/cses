#include <bits/stdc++.h>

#define ll long long
#define ar array
#define up(i,a,b) for(int i=a; i<b; i++)
#define down(i,a,b) for(int i=a; i>b; i--)
#define pb push_back

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    set<ar<int,3>> times;
    up(i,0,n) {
        int a, b;
        cin >> a >> b;
        times.insert({b, a, i});
    }
  
    set<ar<int,2>> rooms;
    int max_room=0;
    unordered_map<int,int> mp;
    
    for (auto el: times) {
        auto it=rooms.lower_bound({el[1], 0});
        if (rooms.empty()||it==rooms.begin()) {
            max_room++;
            rooms.insert({el[0], max_room});
            mp[el[2]]=max_room;
        } else {
            it--;
            int value=(*it)[0];
            while ((*it)[0]==value&&it!=rooms.begin()) it--; 
            if ((*it)[0]!=value) it++; 

            int room=(*it)[1];
            rooms.erase(it);
            rooms.insert({el[0], room});
            mp[el[2]]=room;
        }
    }

    cout << max_room << endl; 
    up(i,0,n) cout << mp[i] << " ";
    cout << '\n';

}
