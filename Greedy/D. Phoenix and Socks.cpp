//Problem Link: https://codeforces.com/contest/1515/problem/D
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
void solve()
{
    ll n, l, r, i, j, x;
    cin>>n>>l>>r;
    ll mx = max(l, r), mn = min(l, r);
    vector<ll> ar(n);
    map<ll, ll> L, R;
    for(i = 0; i < n; i++)
        cin>>ar[i];

    if(l >= r)
    {
        for(i = 0; i < l; i++)
           L[ar[i]]++;
        for(i = l, j = 0; i < n;j++, i++)
            R[ar[i]]++;
    }
    else
    {
        for(i = l, j = 0; i < n;j++, i++)
            L[ar[i]]++;
        for(i = 0; i < l; i++)
            R[ar[i]]++;
        swap(l, r);
    }
    ll dif = (n/2) - r;
    ll ans = 0;
    for(auto xx : L)
    {
        ll c = xx.first;
        ll cnt = xx.second;
//        cout<<c<<" "<<cnt<<nl;
        if(R[c] > 0)
        {
            L[c] -= min(cnt, R[c]);
            R[c] -= min(cnt, R[c]);
        }
        if(L[c] > 1 && dif > 0)
        {
            ll mid = L[c]/2;
            ll sub = min(mid, dif);
            L[c] -= 2*sub;
            dif  -= sub;
            ans += sub;
        }
    }
    if(dif == 0)
    {
        for(auto xx : L)
        {
//            cout<<xx.first<<" # "<<xx.second<<nl;
            if(xx.second > 0) ans += xx.second;
        }
    }
    else
    {
        ans += (2*dif);
        for(auto xx : R)
        {
//            cout<<xx.first<<" # "<<xx.second<<nl;
            if(xx.second > 0) ans += xx.second;
        }
    }
    cout<<ans<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}


