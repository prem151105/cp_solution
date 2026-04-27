#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = 100 / a[i];
        }

        int m = a[0];

        for (int i = 1; i < n; i++) {
            m = gcd(m, a[i]);  
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                c++;
                break;
            }
        }

        if (m == 1 && c==1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}