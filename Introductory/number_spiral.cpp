#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	ll t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		ll row, col;
		cin >> row >> col;

		ll outer = max(row, col);

		ll bottom = (outer-1)*(outer-1) + 1;
		ll top = outer*outer;

		ll num_outer = 2*(outer-1) + 1;
		ll position;
		if (row == col) {
			cout << bottom + num_outer/2 << '\n';
		} else {
			if (row > col) {
				position = col;
			} else {
				position = col - row + num_outer/2 + 1;
			}

			if (outer % 2 == 0) {
				cout << top - position + 1 << '\n';; 
			} else {
				cout << bottom + position - 1 << '\n';;
			}
		}
	}
}