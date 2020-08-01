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

    vector<ar<int,3>> projects;
    up(i,0,n) {
        int a, b, p;
        cin >> a >> b >> p;
        projects.pb({a,b,p});
    }

    sort(projects.begin(), projects.end(), [](ar<int,3> a, ar<int,3> b) {
        if (a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    });
    int f[n];
    f[n-1]=projects[n-1][2];

    down(i,n-2,-1) {
        int ans=f[i+1];
        auto it=lower_bound(projects.begin()+i, projects.end(), projects[i], [](ar<int,3> a, ar<int,3> b) {
            return a[1]<b[0];
        });

        int p=it-projects.begin();
        if (it!=projects.end()) {
            ans=max(ans, projects[i][2]+f[p]);
        }    
        f[i]=ans;
    }

    cout << f[0] << endl;
}	

