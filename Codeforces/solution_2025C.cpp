#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int tc;
    cin >> tc;
 
    while (tc--) {
        int n, k;
        cin >> n >> k;  
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        sort(a.begin(), a.end());
 
        int j = 0;
        int ans = 0;
 
        for (int i = 0; i < n; i++) {
            j=max(i,j);
 
            while (j + 1 < n && (a[j+1] - a[i] < k) && a[j+1]-a[j]<=1 ) {
                j++;
            }
 
            ans = max(ans, j - i + 1);
        }
 
        cout << ans << endl;
    }
 
    return 0; 
}