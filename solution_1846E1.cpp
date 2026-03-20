#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1000000;
bool is_snowflake[MAX_N + 1];

void precompute() {
    
    for (long long k = 2; k * k < MAX_N; ++k) {
        long long current_sum = 1 + k + k * k;
        long long p = k * k;
        
        while (current_sum <= MAX_N) {
            is_snowflake[current_sum] = true;
            if (MAX_N / k < p) break; 
            p *= k;
            current_sum += p;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (is_snowflake[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}