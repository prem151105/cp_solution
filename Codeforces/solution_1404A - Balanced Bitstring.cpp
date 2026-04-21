#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<char> group(k, '?');

        bool ok = true;

        // Step 1: enforce consistency for i % k
        for(int i = 0; i < n; i++){
            if(s[i] == '?') continue;

            if(group[i % k] == '?'){
                group[i % k] = s[i];
            }
            else if(group[i % k] != s[i]){
                ok = false;
                break;
            }
        }

        if(!ok){
            cout << "NO\n";
            continue;
        }

        // Step 2: count in first k
        int c0 = 0, c1 = 0, cq = 0;

        for(int i = 0; i < k; i++){
            if(group[i] == '0') c0++;
            else if(group[i] == '1') c1++;
            else cq++;
        }

        if(c0 > k/2 || c1 > k/2){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}