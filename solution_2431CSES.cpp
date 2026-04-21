#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        ll x;
        cin >> x;

        x--; // make 0-based

        ll len = 1, num = 1; // ✅ fixed

        // Find which digit-length block
        while(x >= len * 9 * num){
            x -= len * 9 * num;
            len++;
            num *= 10;
        }

        // Find actual number
        num += x / len;

        // Find digit index
        x %= len;

        cout << to_string(num)[x] << endl;
    }
    
    return 0;
}