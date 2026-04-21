#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long n,x,y;
        cin >> n >> x >> y;

        long long sum = 0;

        for(int i=0;i<n;i++){
            long long a;
            cin >> a;
            sum += a;
        }

        if((x + sum) % 2 == y % 2)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}