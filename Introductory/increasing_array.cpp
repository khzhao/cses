#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;

	int prev;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (i == 0) {
			prev = val;
		} else {
			if (val < prev) {
				count += prev - val;
			} 
			prev = max(prev, val);
		}
	}	
	cout << count;
}