#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>

#define ll long long

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    int prices[n], pages[n];

    for (int i=0; i<n; i++) {
        cin >> prices[i];
    }
    for (int i=0; i<n; i++) {
        cin >> pages[i];
    }

    int prev[x+1];
    for (int i=0; i<=x; i++) {
        if (i<prices[0]) prev[i]=0;
        else prev[i]=pages[0];
    }
    
    // Fix the max book
    for (int i=1; i<n; i++) {
        int now[x+1];
        memset(now, 0, sizeof(int)*(x+1));

        // Iterate through all money amounts
        for (int j=0; j<=x; j++) {
            if (j>=prices[i]) {
                now[j]=max(now[j], prev[j-prices[i]]+pages[i]);
            }
            now[j]=max(now[j],prev[j]);
        }
        
        for (int k=0; k<=x; k++) {
            prev[k]=now[k];
        }
    }

    cout << prev[x] << endl;
}

