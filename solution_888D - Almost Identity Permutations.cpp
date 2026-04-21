// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/888/D

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <cmath>
#include <array>

using namespace std;
using ll = long long;

void setIO(string File_name) {
    cin.tie(0)->sync_with_stdio(0);
    if (File_name.size()) {
        freopen((File_name + ".in").c_str(), "r", stdin);
        freopen((File_name + ".out").c_str(), "w", stdout);
    }
}

// n - k = C(n - k, n) * !k
// n - k + 1 = C(n - k + 1, n) * !(k - 1);
// ...
// n
//

ll C(int k, int n){
    int j = n - k;
    ll res = 1;
    for(ll i = n; i >= k + 1; i--){
        res *= i;
    }
    for(ll i = 1; i <= j; i++){
        res /= i;
    }
    return res;
}

void sol() {
    vector<int> subfactorial{1, 0, 1, 2, 9, 44};
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    for(int i = 0; i <= k; i++){
        res += C(n - i, n) * subfactorial[i];
    }
    cout << res;
}

int main() {
    setIO("");
    int T = 1;
    //cin >> T;
    while (T--) sol();
    return 0;
}