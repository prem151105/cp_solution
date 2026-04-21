#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define R(i,x,y) for (int i=(x);i>=(y);i--)
#define p2i pair<int,int>
#define ll long long
#define fi first
#define se second
#define nb(x) (1<<((x)-1))
#define x1 __melody1
#define x2 __melody2
#define y1 __melody3
#define y2 __melody4
#define iosoptim ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
const bool MT = 1;
int n,cnt[10005];
void ygg(){
    cin>>n;
    int tmp;
    bool flag=1;
    F(i,1,n*n) {
        cin>>tmp;
        ++cnt[tmp];
        if (cnt[tmp]>n*(n-1)) flag=0;
    }
    if (flag) cout<<"YES\n";
    else cout<<"NO\n";
}
void mark() {
    F(i,1,n*n) cnt[i]=0;
}
int main (){
#ifdef ONLINE_JUDGE
    iosoptim
#endif
    int testcases=1;
    if(MT) cin>>testcases;
    while(testcases--){
        ygg();
        mark();
    }
    return 0;
}