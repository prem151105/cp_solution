#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=n;i++){
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j==0){
                mp[j]++;
                a[i]=a[i]/j;
            }
        }
    }
    for(int auto& p :mp){
        if(p.second()%n==0){
            c++;
        }
        else{
            c=0;
            break;

        }
    }
    if(c>=1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    }
}