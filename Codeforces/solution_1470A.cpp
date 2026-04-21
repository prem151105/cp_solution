#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
 
        vector<int> a(n);
        vector<int> b(m);
 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
 
        sort(a.begin(), a.end(), greater<int>());
 
        long long ans = 0;
        int j = 0;
 
        for(int i = 0; i < n; i++){
            if(j < m && b[j] < b[a[i] - 1]){
                ans += b[j];
                j++;
            }
            else{
                ans += b[a[i] - 1];
            }
        }
 
        cout << ans << endl;
    }
}