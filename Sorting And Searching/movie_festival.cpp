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

    vector<ar<int,2>> movies;
    up(i,0,n) {
        int a, b;
        cin >> a >> b;
        movies.pb({b, a});
    }
    sort(movies.begin(), movies.end());

    int count=1;
    int prev=movies[0][0];
    up(i,1,n) {
        int curr_s=movies[i][1];
        int curr_f=movies[i][0];
        if (curr_s>=prev) {
            count++;
            prev=curr_f;
        }
    }

    cout << count << endl;

    
}
