#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <climits>
#include <cstring>

#define ll long long
#define ar array
#define f(i,a,b) for (int i=a; i<b; i++)

using namespace std;

double ev(int r, int t) {
    double res=0;
    if (r > t) {
        res+=(double)(r-t)/r;
        res+=(double)t/r*(1.-1./t)/2.;
    } else if (r < t) {
        res+=(r>1)*((double)r/t)*(1.-1./r)/2.;
    } else {
        res+=(r>1)*(1.-1./t)/2;
    }   
    return res;
}

int main() {
    int n; 
    cin >> n;

    int contents[n];
    f(i,0,n) cin >> contents[i];
    
    double ans=0;
    f(i,0,n)
        f(j,i+1,n)
            ans+=ev(contents[i],contents[j]);
    
    cout << fixed << setprecision(6) << ans << endl;
    
}
