#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> cows(N);
    vector<int> stalls(N);

    for (int i = 0; i < N; i++) cin >> cows[i];
    for (int i = 0; i < N; i++) cin >> stalls[i];

    // Sort cows in descending order (tallest first)
    // This allows us to see how many stalls the most restricted cows can fit into
    sort(cows.rbegin(), cows.rend());
    // Sorting stalls is optional but keeps the counting logic clean
    sort(stalls.rbegin(), stalls.rend());

    long long total_ways = 1;

    for (int i = 0; i < N; i++) {
        long long choices = 0;
        
        // Count how many stalls can fit the current cow
        for (int j = 0; j < N; j++) {
            if (cows[i] <= stalls[j]) {
                choices++;
            }
        }

        // Subtract 'i' because 'i' taller cows have already taken 
        // 'i' of the available stalls that this cow could have used.
        total_ways *= (choices - i);
    }

    cout << total_ways << endl;

    return 0;
}