#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_set<int> s;
    int j = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(j < n && s.find(a[j]) != s.end()){
            j++;          
            i--;         
        }
        else{
            if(j < n && b[i] != a[j]){
                ans++;
                s.insert(b[i]);
            }
            else{
                j++;
                s.insert(b[i]);
            }
        }
    }

    cout << ans << endl;
}