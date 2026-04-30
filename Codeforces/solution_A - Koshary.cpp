#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    while(tc--){
	int x,y;
	cin>>x>>y;
	if(x%2==0 && y%2==0){
	    cout<<"Yes"<<endl;
	}
	else if(x%2==0 && (y-1)%2==0){
	    cout<<"Yes"<<endl;
	}
	else if((x-1)%2==0 && y%2==0){
	    cout<<"Yes"<<endl;
	}
	else{
	    cout<<"No"<<endl;
	}
    }
	
}
