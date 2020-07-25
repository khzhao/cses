#include <iostream>

using namespace std;

#define ll long long

int main() {
	ll n, sum = 0;
	cin >> n;

	for (ll i = 0; i < n-1; i++) {
		int val;
		cin >> val;
		sum += val;
	}

	cout << n*(n+1)/2 - sum;
}