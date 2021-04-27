//Problem Link: https://www.spoj.com/problems/DICT/
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ULL long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const int N = 25005;
const int M = 21;
ULL hs = 3797;

map<ULL, int> mp;
vector<int> hashes[N * M];
vector<string> ar(N);
void solve()
{
    int n, id = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>ar[i];
        ULL Hash = 0;
        for(int j = 0; j < sz(ar[i]); j++)
        {

            Hash = Hash * hs + ar[i][j];
            if(mp[Hash] == 0) mp[Hash] = ++id;
            hashes[mp[Hash]].pb(i);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        cout << "Case #" << ++casino << ":\n";
        string s;
        cin>>s;
        ULL s_hash = 0;
        for(int i = 0; i < sz(s); i++)
            s_hash = s_hash * hs + s[i];
        set<string> ans;
        for(auto x : hashes[mp[s_hash]])
            ans.insert(ar[x]);
        ans.erase(s);
        if(ans.empty()) cout<<"No match.\n";
        else
        {
            for(auto x : ans)
                cout<<x<<nl;
        }
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


