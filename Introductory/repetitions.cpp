#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	string dna;
	cin >> dna;

	char prev = dna[0];
	int largest = 1;
	int count = 1;
	for (int i=1; i < dna.size(); i++) {
		if (dna[i] == dna[i-1]) {
			count++;
		} else {
			largest = max(largest, count);
			count = 1;
		}
		prev = dna[i];
	}
	largest = max(largest, count);

	cout << largest;
}