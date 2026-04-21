#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        int k = n / 2;
        cout << (long long)(k + 1) * (k + 1) << endl;
    } else {
        int k = n / 2;
        cout << (long long)2 * (k + 1) * (k + 2) << endl;
    }

    return 0;
}