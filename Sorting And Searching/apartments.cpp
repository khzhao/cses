#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>

#define ll long long
#define ar array

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int desired[n];
    int actual[m];

    for (int i=0; i<n; i++) cin >> desired[i];
    for (int i=0; i<m; i++) cin >> actual[i];
    
    sort(desired, desired+n);
    sort(actual, actual+m);
    
    int serviced=0, point_a=0, point_d=0;
    while (point_d<n && point_a<m) {
        int curr_desired=desired[point_d];
        int available=actual[point_a];

        if (available<=curr_desired+k && available>=curr_desired-k) {
            serviced++; point_a++; point_d++;
        } 

        if (available>curr_desired+k) point_d++;
        if (available<curr_desired-k) point_a++;
    }

    cout << serviced << endl;
}
