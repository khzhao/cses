#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <unordered_map>

#define ll long long
#define ar array

using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<char,int> counts;
    vector<char> odd_chars;
    for (char c: s) counts[c]++;

    int odds=0;
    for (auto c: counts) {
        if (c.second%2) {
            odds++;
            odd_chars.push_back(c.first);
        }
    }

    if (odds>1) {
        cout << "NO SOLUTION" << endl; 
        return 0;
    }

    string odd_string;
    for (char odd: odd_chars) odd_string+=string(counts[odd], odd);

    string t;
    for (auto c: counts) {
        if (c.second%2==0) {
            t+=string(c.second/2,c.first);
        }
    }

    cout << t + odd_string + string(t.crbegin(), t.crend()) << endl;
}
