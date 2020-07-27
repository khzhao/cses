#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <set>

#define ll long long
#define ar array

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> nums;
    
    int tmp;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        if (!nums.count(tmp)) nums.insert(tmp);
    }

    cout << nums.size() << endl;
}

