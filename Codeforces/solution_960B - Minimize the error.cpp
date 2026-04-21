#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k1,k2;
    cin >> n >> k1 >> k2;

    vector<int>a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        pq.push(abs(a[i] - b[i]));
    }

    int k = k1 + k2;

    while(k--){
        int x = pq.top();
        pq.pop();

        if(x > 0) x--;
        else x++;  

        pq.push(x);
    }

    long long ans = 0;
    while(!pq.empty()){
        long long d = pq.top();
        pq.pop();
        ans += d*d;
    }

    cout << ans << endl;
}