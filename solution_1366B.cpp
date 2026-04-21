#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        int m;
        cin >> n >> x >> m;

        long long L = x, R = x;

        while(m--){
            long long l, r;
            cin >> l >> r;

            // check overlap
            if(r >= L && l <= R){
                L = min(L, l);
                R = max(R, r);
            }
        }

        cout << (R - L + 1) << endl;
    }
}