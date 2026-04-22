#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>ans(n,vector<int>(n,0)); // define the n*n grid
        int x=n/2;
        int y=n/2;
        if(n%2==0){
            x--;
            y--;
        }
        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        int v=0;
        int step=1;
        while(v<n*n){
            for(int d=0;d<4;d++){
                int dx=dir[d].first;
                int dy=dir[d].second;
                for(int i=0;i<step;i++){
                    x+=dx;
                    y+=dy;
                    if(x>=0 && x<n && y>=0 && y<n){
                        ans[x][y]=v++;
                        if(v>=n*n){
                            break;
                        }
                    }
                }
                if(v>=n*n){
                    break;
                }
                if(d%2==1){
                    step++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}