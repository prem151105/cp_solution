#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        long long W;
        cin >> n >> W;

        multiset<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }

        int height = 0;

        while (!s.empty()) {
            long long space = W;
            height++;

            while (true) {
                auto it = s.upper_bound(space);
                if (it == s.begin()) break;

                --it;
                space -= *it;
                s.erase(it);
            }
        }

        cout << height << "\n";
    }
}