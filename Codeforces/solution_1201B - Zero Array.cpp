#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long sum = 0;
    int mx = 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    if(sum % 2 == 0 && mx <= sum - mx){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}