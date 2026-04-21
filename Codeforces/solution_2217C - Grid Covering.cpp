#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(gcd(a,n)==1 && gcd(b,m)==1 && gcd(n,m)<=2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
}