#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> a(n);
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
 
        sort(a.begin(), a.end(), greater<int>());

        bool ok = true;

        for(int i=0;i<n-1;i++){
            if(a[i] == a[i+1]){
                cout << -1 << endl;
                ok = false;  // ✅ FIXED
                break;
            }
        }

        if(ok){
            for(int i=0;i<n;i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}