#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;

    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<long long> cnt(n+1, 0); // difference array

    while(q--){
        int l,r;
        cin >> l >> r;
        l--; r--;

        cnt[l] += 1;
        if(r+1 < n) cnt[r+1] -= 1;
    }

    // prefix sum
    for(int i=1;i<n;i++){
        cnt[i] += cnt[i-1];
    }

    cnt.pop_back(); // size n

    sort(a.begin(), a.end());
    sort(cnt.begin(), cnt.end());

    long long ans = 0;

    for(int i=0;i<n;i++){
        ans += cnt[i] * a[i];  // both sorted ascending
    }

    cout << ans << endl;
}