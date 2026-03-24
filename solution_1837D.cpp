#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total_balance = 0;
    for (char c : s) {
        if (c == '(') total_balance++;
        else total_balance--;
    }

    if (total_balance != 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n);
    int balance = 0;
    int current_type = 0;
    set<int> used_types;

    for (int i = 0; i < n; i++) {
        if (balance == 0) {
            if (s[i] == '(') current_type = 1; 
            else current_type = 2;            
        }

        ans[i] = current_type;
        used_types.insert(current_type);

        if (s[i] == '(') balance++;
        else balance--;
    }

  
    if (used_types.size() == 1) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << "";
        }
    } else {
        cout << 2 << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
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