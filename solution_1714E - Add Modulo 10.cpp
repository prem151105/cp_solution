#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Function to perform the operation: a = a + (a % 10)
int next_val(int n) {
    return n + (n % 10);
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_zero_or_five = false;
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 5 == 0) {
            has_zero_or_five = true;
            // If it ends in 5, make it end in 0
            if (a[i] % 10 == 5) {
                a[i] = next_val(a[i]);
            }
        }
    }
 
    if (has_zero_or_five) {
       
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] != a[i + 1]) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    } else {
        // Case B: Bring all numbers to end in 2
        for (int i = 0; i < n; ++i) {
            while (a[i] % 10 != 2) {
                a[i] = next_val(a[i]);
            }
        }
        // Check if all are same modulo 20
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] % 20 != a[i + 1] % 20) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}