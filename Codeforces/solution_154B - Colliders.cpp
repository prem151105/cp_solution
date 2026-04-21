#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> get_factors(int x){
    vector<int> f;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            f.push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) f.push_back(x);
    return f;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<bool> on(n+1,false);
    unordered_map<int,int> used; // prime -> collider

    while(m--){
        char t;
        int x;
        cin>>t>>x;

        if(t=='+'){
            if(on[x]){
                cout<<"Already on\n";
                continue;
            }

            vector<int> f = get_factors(x);

            bool ok = true;
            int conflict = -1;

            for(int p: f){
                if(used.count(p)){
                    ok = false;
                    conflict = used[p];
                    break;
                }
            }

            if(!ok){
                cout<<"Conflict with "<<conflict<<"\n";
            }
            else{
                for(int p: f){
                    used[p] = x;
                }
                on[x] = true;
                cout<<"Success\n";
            }
        }
        else{
            if(!on[x]){
                cout<<"Already off\n";
            }
            else{
                vector<int> f = get_factors(x);
                for(int p: f){
                    used.erase(p);
                }
                on[x] = false;
                cout<<"Success\n";
            }
        }
    }
}