#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>

#define ll long long
#define ar array
#define f(i,a,b) for (int i=a; i<b; i++)

using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<string> outs;
    int ans=0;
    int n=s.size();
    do {
        ans++;
        outs.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    
    cout << ans << endl;
    for (auto el: outs) cout << el << endl;

}
