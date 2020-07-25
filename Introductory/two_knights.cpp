#include <iostream>

using namespace std;

#define ll long long

// Note to self:
// There is an easier way to solve it
// The number of conflicts caused by a board of size kxk
// is 4*(k-1)*(k-2)

int main() {
	ll n;
	cin >> n;

	int first[7] = {0, 6, 28, 96, 252, 550, 1056};

	ll prev;

	for (int i = 1; i < n+1; i++) {
		if (i <= 7){
			prev = first[i-1];
		}
		else {
			ll unsafe = 0;

			unsafe += 4 * (i - 4) + 10;
			unsafe *= 2;
			unsafe -= 4;

			ll top = i*i;
			ll bottom = (i-1)*(i-1);
			ll total = top*(top-1)/2 - bottom*(bottom-1)/2;
			prev += total - unsafe;
		}

		cout << prev << endl;
	}
}