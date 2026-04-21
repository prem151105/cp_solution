#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int xor_sum=0;
        for(int i=0;i<n;i++){
            xor_sum^=a[i];
        }
        if(xor_sum==0){
            cout<<"YES"<<endl;
        }else{
            int cnt=0;
            int current_xor=0;
            for(int i=0;i<n;i++){
                current_xor^=a[i];
                if(current_xor==xor_sum){
                    cnt++;
                    current_xor=0;
                }
            }
            if(cnt>=2){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}