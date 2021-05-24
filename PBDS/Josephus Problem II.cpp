//Problem Link: https://cses.fi/problemset/task/2163/
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int casino = 0;
void solve()
{
    ll n, k;
    cin>>n>>k;
    ordered_set<ll> os;
    for(ll i = 1; i<=n; i++)
        os.insert(i);

    ll i = k;
    while(!os.empty())
    {
        i %= sz(os);
        ll cur = *os.find_by_order(i);
        cout<<cur<<" ";
        os.erase(cur);
        i += k;
    }
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


