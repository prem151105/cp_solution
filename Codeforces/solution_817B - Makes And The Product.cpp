#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> counts;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++;
    }
    
    sort(a.begin(), a.end());
    
    long long x = a[0], y = a[1], z = a[2];
    long long ans = 0;
 
    if (x == z) {
        long long cnt = counts[x];
        ans = cnt * (cnt - 1) * (cnt - 2) / 6;
    } else if (x == y) {
        ans = counts[z];
    } else if (y == z) {
        long long cnt = counts[z];
        ans = cnt * (cnt - 1) / 2;
    } else {
        ans = counts[z];
    }
 
    cout << ans << endl;
    return 0;
}