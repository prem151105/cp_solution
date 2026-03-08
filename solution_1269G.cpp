#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
		int n,k;
		cin>>n>>k;
		vector<int>a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			a[i]=a[i]*pow(2,i);
		}
		int l=0;
		for(int i=0;i<n;i++){
			if(a[i+1]>a[i]){
				c+=1;
				if(c==k){
                   ans++;
				   l++;
				}
			}
			else{
				c=0;
				l=i;
			}
		}
		cout<<ans<<endl;

}

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
		return 0;
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/
