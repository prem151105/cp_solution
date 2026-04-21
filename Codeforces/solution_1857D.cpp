#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        vector<int>c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
             c[i]=a[i]-b[i];
        }
        int c=0;
        vector<int>ans;
        int mx=*max_element(c.begin(),a.end());
        for(int i=0;i<n;i++){
            if(c[i]==mx){
                c++;
                ans.push_back(i+1);
            }
        }
        cout<<c<<endl;
        for(auto p:ans){
            cout<<p<<" ";
        }
        cout<<endl;

    }
}