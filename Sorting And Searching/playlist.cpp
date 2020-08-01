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
    int n;
    cin >> n;

    vector<int> songs(n);
    up(i,0,n) cin >> songs[i];
    set<int> listened;

    int p1=0;
    int p2=0;
    int best=0;
    while (p1<n&&p2<n) {
        if (!listened.count(songs[p2])) {
            listened.insert(songs[p2]);
            p2++;
            best=max((int)listened.size(),best);
        } else {
            listened.erase(songs[p1]);
            p1++; 
        }
    }

    cout << best << endl;

}

