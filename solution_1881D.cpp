#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        map<int,int> mp;

        for(int i = 0; i < n; i++){
            int x = a[i];
            for(int j = 2; j * j <= x; j++){
                while(x % j == 0){
                    mp[j]++;
                    x /= j;
                }
            }
            if(x > 1) mp[x]++;
        }

        bool ok = true;

        for(auto &p : mp){
            if(p.second % n != 0){
                ok = false;
                break;
            }
        }

        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}