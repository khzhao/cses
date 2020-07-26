#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    int n, money;
    cin >> n >> money;

    ll modulo=1e9+7;
    vector<int> denoms;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        denoms.push_back(tmp);
    }


    ll f[money+1];
    f[0]=1;
    for (int i=1; i<money+1; i++) f[i]=0;
    
    for (auto coin : denoms) {
        for (int i=1; i<=money; i++) {
            if (coin <= i) {
                f[i] = (f[i] + f[i-coin]) % modulo;
            }
        }
    }   

    cout << f[money] << endl;
}
