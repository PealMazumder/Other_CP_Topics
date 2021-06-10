//Problem Link: http://codeforces.com/contest/1538/problem/C
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
void solve()
{
    ll n, i, j, l, r;
    cin>>n>>l>>r;
    ll ar[n];
    for(i = 0; i < n; i++){
        cin>>ar[i];
    }
    sort(ar, ar +n);
    ll ans = 0;
    for(i = 0; i<n; i++)
    {
        ll tarl = l - ar[i];
        ll tarr = r - ar[i];
        ll a = lower_bound(ar + i+1, ar + n, tarl) - (ar + i+1);
        ll b = upper_bound(ar + i+1, ar + n, tarr) - (ar + i+1);
        ans += (b - a);
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

