//Problem Link: https://cses.fi/problemset/task/1628/
//Custom Hash: https://codeforces.com/blog/entry/62393
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve()
{
    int n, x, ele;
    cin>>n>>x;
    int mid = n/2;
    vector<int> a(mid), b((n+1)/2);
    for(int i = 0; i<mid; i++)
        cin>>a[i];
    for(int i = mid, j = 0; i<n; i++, j++)
        cin>>b[j];
    unordered_map<int, int, custom_hash> mp;
    for(int mask = 0; mask < (1 << sz(a)); mask++)
    {
        int sum = 0;
        int cur = mask, i = 0;
        while(cur)
        {
            if(cur & 1) sum += a[i];
            i++, cur >>= 1;
            if(sum > x) break;
        }
        mp[sum]++;
    }
    ll ans = 0;
    for(int mask = 0; mask < (1 << sz(b)); mask++)
    {
        int sum = 0;
        int cur = mask, i = 0;
        while(cur)
        {
            if(cur & 1) sum += b[i];
            i++, cur >>= 1;
            if(sum > x) break;
        }
        if(mp.find(x-sum) != mp.end()) ans += mp[x - sum];
    }
    cout<<ans<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
    solve();
    return 0;
}

