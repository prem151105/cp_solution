#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<int> p;

        p.push_back(a[0]);

        for(int i = 1; i < n-1; i++){
            if( (a[i] > a[i-1] && a[i] > a[i+1]) ||
                (a[i] < a[i-1] && a[i] < a[i+1]) ){
                p.push_back(a[i]);
            }
        }

       
        p.push_back(a[n-1]);

        cout << p.size() << endl;
        for(auto &k : p){
            cout << k << " ";
        }
        cout << endl;
    }
}