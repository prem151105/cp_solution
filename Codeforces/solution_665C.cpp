#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();

    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            for(char c='a';c<='z';c++){
                if(c!=s[i-1] && (i+1>=n || c!=s[i+1])){
                    s[i]=c;
                    break;
                }
            }
        }
    }

    cout<<s;
}