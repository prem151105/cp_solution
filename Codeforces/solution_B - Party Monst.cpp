#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    while(tc--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int c=0;
	for(int i=0;i<n;i++){
	    if(s[i]=='('){
	        c++;
	    }
	    else{
	        c--;
	    }
	    
	}
	if(c==0){
	    cout<<"Yes"<<endl;
	}
	else{
	    cout<<"No"<<endl;
	}
    }
	
}
