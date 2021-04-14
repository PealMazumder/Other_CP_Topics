//Problem Link: https://codeforces.com/problemset/problem/888/E
#include<bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define ll long long
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
vector<ll> a, b;
int n, m, i;
int ar[36];
ll ans = -1;
void sub(int pos, ll sum, int n, bool ck)
{
    if(pos > n)
    {
        if(ck == 0)a.pb(sum);
        else b.pb(sum);
        ans = max(ans, sum);
        return;
    }
    sub(pos+1, (sum + ar[pos])%m, n, ck);
    sub(pos+1, sum, n, ck);
}
void solve()
{
    cin>>n>>m;
    for(i = 0; i < n; i++)
        cin>>ar[i];
    int mid = n/2;
    sub(0, 0, mid, 0);
    sub(mid+1, 0, n-1, 1);

    sort(all(b));
    int mm = m-1;
    for(auto xx : a)
    {
        ll tm = mm - xx;
        auto aa = lower_bound(all(b), tm);
        if(aa == b.end() || *aa > tm)
            aa--;
        if(*aa <= tm)
            ans = max(ans, (xx + *aa) % m);
    }
    cout<<ans<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}


