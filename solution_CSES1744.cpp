#include<bits/stdc++.h>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h; 
    // here dp[i][j] is the minimum number of moves to make there are all square in rectangle  from (0,0) to (i,j)
    // base case : if(i==j) dp[i][j]=0;
    // transition eqn : dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1) // vertical cut
    // transition eqn : dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1) // horizontal cut

    vector<vector<int>> dp(w+1, vector<int>(h+1, 0));

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {

            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1e9;

                // Vertical cuts
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[k][j] + dp[i-k][j] + 1);
                }

                // Horizontal cuts
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
    }

    cout << dp[w][h] << endl;
}