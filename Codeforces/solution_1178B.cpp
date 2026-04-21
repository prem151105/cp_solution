#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    long long total_w = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'v' && s[i+1] == 'v') {
            total_w++;
        }
    }

    long long ans = 0;
    long long left_w = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'v' && i + 1 < n && s[i+1] == 'v') {
            left_w++;
        } 
        else if (s[i] == 'o') {
            ans += left_w * (total_w - left_w);
        }
    }

    cout << ans << endl;

    return 0;
}