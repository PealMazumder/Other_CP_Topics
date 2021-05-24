//Problem Link: https://cses.fi/problemset/task/1073/
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
    ll n, i, j;
    cin>>n;
    vector<ll> ar(n);
    set<ll> st;
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for(i = 0; i < n; i++)
    {
        cin>>ar[i];
        auto it = st.upper_bound(ar[i]);
        if(it == st.end())
            st.insert(ar[i]), mp[ar[i]]++, ans++;
        else
        {
            mp[*it]--;
            if(mp[*it] == 0)
                st.erase(*it);
            st.insert(ar[i]);
            mp[ar[i]]++;
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
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}

