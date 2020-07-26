#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define ll long long

using namespace std;

int main() {
    int n, money;
    cin >> n >> money;

    ll modulo=1e9+7;

    ll f[money+1];
    memset(f, 0, sizeof(ll)*(money+1));
    f[0]=1;

    vector<int> denoms;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        denoms.push_back(tmp);
    }

    for (int i=1; i<= money; i++) {
        for (auto coin : denoms) {
            if (i-coin >= 0) f[i] = (f[i] + f[i-coin]) % modulo;
        }
    }

    cout << f[money] << endl;
}
