#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }

        vector<int> s;
        for (auto &p : freq) {
            s.push_back(p.second);
        }

        sort(s.rbegin(), s.rend());

        int ans = s[0];
        int c = s[0];

        for(int i = 1; i < (int)s.size(); i++){
            if(s[i] >= c){
                ans += c - 1;
                c -= 1;
            }
            else{
                ans += s[i];
                c = s[i];
            }
            if(c == 0) break;
        }

        cout << ans << endl;
    }
    return 0;
}