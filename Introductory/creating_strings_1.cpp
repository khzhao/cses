#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <map>
#include <stack>

#define ll long long
#define ar array

using namespace std;

// Can be solved with the next_permutation library 
// function

int fact(int n) {
    if (n==0) return 1;
    return n*fact(n-1);
}

int c(int n, int k) {
    return fact(n)/(fact(n-k)*fact(k));
}

map<char,int> counts_string(string s) {
    map<char,int> counts;
    for (char c: s) counts[c]++;
    return counts;
}

int count_string(map<char,int>& counts, int n) {
    int total=n; 
    int num_strings=1;
    for (auto el: counts) {
        num_strings*=c(total,el.second);
        total-=el.second;
    }

    return num_strings;
}

int main() {
    string s;
    cin >> s;

    map<char,int> counts = counts_string(s);
    cout << count_string(counts, s.size()) << endl;

    stack<string> stk;
    for (auto it=counts.crbegin(); it!=counts.crend(); it++)
        stk.push(string(1,it->first));

    while (!stk.empty()) {
        string top=stk.top();
        stk.pop();
        if (top.size()<s.size()) {
            map<char,int> top_count=counts_string(top);
            for (auto it=counts.crbegin(); it!=counts.crend(); it++) {
                char c=it->first;
                if (top_count[c]<counts[c]) {
                    stk.push(top+c);
                }
            }
        } else if (top.size()==s.size()) {
            cout << top << endl;
        }   
    }
}
