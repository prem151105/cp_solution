// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <functional>
#include <numeric>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#ifdef __x86_64__
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif
using namespace std;
 
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF (int)1e17
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define emb emplace_back
#define em emplace
#define mpr make_pair
#define ff first
#define int long long
#define double long double
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define coutyes cout << "YES" << endl;
#define coutno cout << "NO" << endl;
#define show(x)            \
    for (auto it : x)      \
        cout << it << " "; \
    cout << endl;
#define showp(v)           \
    for (auto [u, v_] : v) \
        cout << u << " " << v_ << endl;
#define showt(v)              \
    for (auto [u, v_, w] : v) \
        cout << u << " " << v_ << " " << w << endl;
 
const int N = 2e5 + 5;
int fact[N], invfact[N];
 
int power(int base, int exp)
{
    int res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
 
int modinv(int n)
{
    return power(n, MOD - 2);
}
 
void init()
{
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 2; i >= 1; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}
 
int ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}
vector<int> sieve;
void si()
{
    sieve.assign(N + 10, 0);
    for (int i = 2; i < N + 10; i++)
    {
        if (sieve[i])
            continue;
        for (int j = i * i; j < N + 10; j += i)
        {
            sieve[j] = 1;
        }
    }
}
int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
void sol()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
 
    multiset<int> ms, ms1, m;
    map<int,int>mp,mp1;
    int i = 0, j = -1;
    vector<int> temp;
    while (j - i + 1 < k && j < n)
    {
        j++;
        if (j == n)
            break;
        temp.pb(a[j]);
        mp[a[j]]++;
        mp1[b[j]]++;
    }
    for (auto it : temp)
    {
        while (mp1[it]!=mp[it])
        {
            if (mp1[-1]==0)
            {
                coutno;
                return;
            }
            mp1[-1]--;
            mp1[it]++;
            m.insert(it);
        }
    }
    // show(ms1)z
    while (j < n)
    {
        j++;
        if (j == n)
            break;
        if (a[i] == a[j])
        {
            if (b[i] == b[j] || b[j] == -1)
            {
                i++;
                continue;
            }
            if(b[i]==-1)
            {
                if (m.find(a[i]) == m.end())
                {
                 
                    coutno;
                    return;
                }
                m.erase(m.find(a[i]));
                mp[a[i]]--;
                mp1[a[i]]--;
            }
            else {
                mp[a[i]]--;
                mp1[a[i]]--;
            }
            mp1[b[j]]++;
            mp[a[j]]++;
            while (mp[a[j]] != mp1[a[j]])
            {
                if (mp1[-1]==0)
                {
                    coutno;
                    return;
                }
                mp1[-1]--;
                mp1[a[j]]++;
                m.insert(a[j]);
            }
            i++;
        }
        else
        {
            if (b[i] == -1)
            {
                if (m.find(a[i]) == m.end())
                {
                    coutno;
                    return;
                }
                m.erase(m.find(a[i]));
                mp[a[i]]--;
                mp1[a[i]]--;
            }
            else
            {
                if (a[i] != b[i])
                {  
                    coutno;
                    return;
                }
                mp[a[i]]--;
                mp1[a[i]]--;
            }
            mp1[b[j]]++;
            mp[a[j]]++;
            // showp(mp1)
            // showp(mp)
            while (mp[a[j]] != mp1[a[j]])
            {
                if (mp1[-1]==0)
                { cout<<j;
                    coutno;
                    return;
                }
                mp1[-1]--;
                mp1[a[j]]++;
                m.insert(a[j]);
            }
            i++;
        }
    }
    coutyes;
}
 
int32_t main()
{
 
    fastio();
    int t = 1;
    cin >> t;
    while (t--)
        sol();
 
    return 0;
}
//  (•ᴗ•)
//   /|\
//   / \