//Problem Link: https://toph.co/p/chikongunia
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const int N = 1000006;
const ULL base = 3797;
ULL F[N];
vector<ULL> H;

void solve()
{
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i-1] * base;
    int n, m;
    cin>>n>>m;
    vector<string> str(n);
    unordered_map<ULL, ll> mp;
    for(int i = 0; i<n; i++)
    {
        cin>>str[i];
        ULL curr_hs = 0;
        for(int j = 0; j < m; j++)
            curr_hs = curr_hs * base + str[i][j];
        mp[curr_hs]++;
        H.pb(curr_hs);
    }
    ll ans = 0;
    for(int i = 0; i < m; i++)
    {
        unordered_map<ULL, ll> same;
        ll cnt = 0;
        for(int j = 0; j < n; j++)
        {
            ULL curr = H[j] + ('0' - str[j][i]) * F[(m - i - 1)];
            same[curr]++;
        }
        for(auto xx : same)
            ans += ((xx.second * (xx.second - 1))/2);

        for(auto xx : mp) //Over-counting handle
            ans -= ((xx.second * (xx.second - 1))/2);
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
//Input
//5 2
//ab
//ab
//ab
//ba
//ba
//Output
//0

