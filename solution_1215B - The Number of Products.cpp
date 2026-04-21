#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> pref(n);
    
    pref[0] = (a[0] < 0);
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + (a[i] < 0);
    }

    long long cnt[2] = {1, 0};
    long long pos = 0, neg = 0;

    for(int i=0;i<n;i++){
        int p = pref[i] % 2;

        pos += cnt[p];        
        neg += cnt[p ^ 1];    

        cnt[p]++;
    }

    cout << neg << " " << pos << endl;
}