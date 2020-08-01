#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <unordered_set>

#define ll long long
#define ar array

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int weights[n];
    for (int i=0; i<n; i++) cin >> weights[i];
    sort(weights, weights+n);

    int gondolas=0;
    int point=0, point_2=n-1;

    while (point<point_2) {
        while (point<point_2&&weights[point]+weights[point_2]>x) point_2--;
        if (point>=point_2) break;
        point++; point_2--;
        gondolas++;
    }

    cout << n-gondolas << endl;
}
