#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        if(n % 2 == 0){
            cout << n/2 << " " << n/2 << endl;
        }
        else{
            int d = -1;

    
            for(int i = 3; i * i <= n; i++){
                if(n % i == 0){
                    d = i;
                    break;
                }
            }

            if(d == -1){
                cout << 1 << " " << n-1 << endl;
            }
            else{
                int a = n / d;
                cout << a << " " << n - a << endl;
            }
        }
    }
}