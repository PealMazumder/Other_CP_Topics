//Problem Link: https://codeforces.com/contest/906/problem/D
/// Related Tutorial: https://cp-algorithms.com/algebra/phi-function.html
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const int N = 100005;
vector<ll> arr(N);
map<ll, ll> mp;
ll MOD(ll n, ll m)
{
    if(n < m) return n;
    return m + (n % m);
}
ll phi(ll n)
{
    ll cpyN = n;
    if(mp.find(n) != mp.end())
        return mp[n];
    ll ans = n;
    for(ll p = 2; p * p <= n; p++)
    {
        if(n % p == 0)
        {
            while(n % p == 0) n /= p;
            ans -= ans/p;
        }
    }
    if(n > 1) ans -= ans/n;
    mp[cpyN] = ans;
    return ans;

}
ll power(ll a, ll n, ll m)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)// IF ODD
            res = MOD(res * a, m), n--;
        n /= 2, a = MOD(a * a, m);
    }
    return res;
}

ll solve(ll l, ll r, ll m)
{
    if(m == 1 || l == r) return MOD(arr[l], m); ///a^(b^c), if arr[l] = c, then simply return c or m + (c % m);
    return power(arr[l], solve(l+1, r, phi(m)), m);/// a^(b^(c^d)) if arr[l] == a, then solve going to calculate (b^(c^d))
    // (a^((b^c) % phi(m))) % m --> (a ^((b^(c % phi(phi(m))) % phi(m)))) % m
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    ll n, m, i, j, x, q, l, r;
    cin>>n>>m;
    for(i = 1; i <= n; i++)
        cin>>arr[i];
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        ll ans = solve(l, r, m);
        cout<<ans % m<<nl;
    }
    return 0;
}
