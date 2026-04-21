#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    int l = 0;
    long long sum = 0;

    for(int r = 0; r < n; r++){
        sum += a[r].second;

        while(a[r].first - a[l].first >= m){
            sum -= a[l].second;
            l++;
        }

        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}