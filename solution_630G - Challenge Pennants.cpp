#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
// function to compute nCr
ll nCr(int n, int r) {
    if (r > n) return 0;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}
 
int main() {
    int n;
    cin >> n;
 
    ll ways_bug = nCr(n + 4, 5);   // C(n+4,5)
    ll ways_feature = nCr(n + 2, 3); // C(n+2,3)
 
    cout << ways_bug * ways_feature << endl;
 
    return 0;
}