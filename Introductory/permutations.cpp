#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;


	if (n <= 3) {
		if (n == 2 || n == 3)
			cout << "NO SOLUTION";
		else cout << "1";
	} else {
		cout << "2";
		for (int i = 4; i <= n; i+=2) {
			cout << " " << i;
		}
		for (int i = 1; i <= n; i+=2) {
			cout << " " << i;
		}
	}
}