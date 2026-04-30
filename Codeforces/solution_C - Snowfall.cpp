#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) cin >> a[i];
         vector<int>b;
         vector<int>c;
         vector<int>d;
         vector<int>e;
         for(int i=0;i<n;i++){
             if(a[i]%6==0){
                 e.push_back(a[i]);
             }
             else if(a[i]%2==0){
                 c.push_back(a[i]);
             }
             else if(a[i]%3==0){
                 d.push_back(a[i]);
             }
             else{
                 b.push_back(a[i]);
             }
         }
         for(int i=0;i<e.size();i++){
             ans.push_back(e[i]);
         }
         for(int i=0;i<c.size();i++){
             ans.push_back(c[i]);
         }
         for(int i=0;i<b.size();i++){
             ans.push_back(b[i]);
         }
         for(int i=0;i<d.size();i++){
            ans.push_back(d[i]);
         }
         
         reverse(ans.begin(),ans.end());
         for(int i=0;i<n;i++){
             cout<<ans[i]<<" ";
         }
         cout<<endl;
    }
}