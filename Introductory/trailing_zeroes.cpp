#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll num_fives = n / 5;
    
    int start = 2;
    while (n / ((int) pow(5, start))) {
        num_fives += n / ((int) pow(5, start));
        start++;
    }

    cout << num_fives << endl;
}
