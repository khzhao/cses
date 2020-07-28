#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

int main() {
	int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        
        if ((a+b)%3) cout << "NO" << endl;
        else {
            if (a<b/2 || b<a/2) cout << "NO" << endl;
            else {
                if (((a+1)%3==0&&(b+2)%3==0)||((a+2)%3==0&&(b+1)%3==0)
                    ||(a%3==0&&b%3==0)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}
