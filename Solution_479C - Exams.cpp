#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    int current_day = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second >= current_day) {
            current_day = a[i].second;
        } else {
            current_day = a[i].first;
        }
    }

    cout << current_day << endl;

    return 0;
}