#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        vector<long long>a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        string s;
        cin>>s;

        // prefix XOR
        vector<long long> px(n+1, 0);
        for(int i=1;i<=n;i++){
            px[i] = px[i-1] ^ a[i-1];
        }

        long long g1=0, g2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') g1 ^= a[i];
            else g2 ^= a[i];
        }

        int q;
        cin>>q;

        while(q--){
            int qt;
            cin>>qt;

            if(qt==1){
                int l,r;
                cin>>l>>r;

                long long X = px[r] ^ px[l-1];
                g1 ^= X;
                g2 ^= X;
            }
            else{
                int x;
                cin>>x;
                if(x==0) cout<<g1<<" ";
                else cout<<g2<<" ";
            }
        }
        cout<<"\n";
    }
}