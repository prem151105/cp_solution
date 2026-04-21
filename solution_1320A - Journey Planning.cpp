#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    // Map to store: (b[i] - i) -> total beauty sum for this group
    map<int, long long> groups;
 
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        
        // Calculate the constant key for this city
        int key = b - i;
        
        // Add this city's beauty to its respective group
        groups[key] += b;
    }
 
    long long max_beauty = 0;
    
    // Find the maximum sum accumulated in any group
    for (auto const& [key, sum] : groups) {
        max_beauty = max(max_beauty, sum);
    }
 
    cout << max_beauty << endl;
 
    return 0;
}