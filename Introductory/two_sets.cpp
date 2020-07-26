#include <iostream>
#include <vector>
#include <unordered_set>

#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    if (n % 4 > 0 && (n+1) % 4 > 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        ll half = n*(n+1)/4;
        ll top = (n % 4 == 0) + n;
        ll start = n;
        unordered_set<int> first;

        while (half > 0) {
            if (start > 0) first.insert(start);
            if (top - start > 0) first.insert(top - start);
            half -= top;
            start--;
        }    

        cout << first.size() << endl;
        for (int i=1; i<=n; i++) {
            if (first.count(i)) cout << i << " ";
        }
        cout << endl;

        cout << n - first.size() << endl;
        for (int i=1; i<=n; i++) {
            if (!first.count(i)) cout << i << " ";
        }
    }
}

