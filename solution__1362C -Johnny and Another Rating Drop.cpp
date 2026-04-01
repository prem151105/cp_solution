#include <iostream>
 
using namespace std;
 
void solve() {
    long long n;
    cin >> n;
    
    long long total_unfairness = 0;
    
    // Summing floor(n / 2^i) for all i >= 0
    while (n > 0) {
        total_unfairness += n;
        n /= 2;
    }
    
    cout << total_unfairness << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}