//Problem Link: https://www.spoj.com/problems/QTREE2/
#include<bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define ll long long
using namespace std;
const int N = 10005;
int L[N];
ll Cost[N];
int P[N][20];
vector<pair<int, int>> adj[N];
void dfs(int node, int par, int d, ll c)
{
    L[node] = d, P[node][0] = par, Cost[node] = c;
    for(auto child : adj[node])
        if(child.first != par)
            dfs(child.first, node, d+1, c + child.second);
}
void init()
{
    memset(P, -1, sizeof P);
    dfs(1, -1, 0, 0);
    for(int j = 1; j<20; j++)
    {
        for(int i = 1; i < N; i++)
        {
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int LCA(int a, int b)
{
    if(L[a] > L[b]) swap(a, b);
    int d = L[b] - L[a];
    while(d > 0)
    {
        int i = log2(d);
        b = P[b][i];
        d -= (1 << i);
    }
    if(a == b) return a;
    for(int i = 19; i>=0; i--)
        if(P[a][i] != -1 && P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}
int findNode(int a, int k)
{
    while(k > 0)
    {
        int i = log2(k);
        a = P[a][i];
        k -= (1 << i);
    }
    return a;
}
void solve()
{
    int n, a, b, c, k;
    cin>>n;
    for(int i = 0; i<=n; i++)
    {
        L[i] = 0, Cost[i] = 0;
        adj[i].clear();
    }
    for(int i = 0; i<n-1; i++)
    {
        cin>>a>>b>>c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    init();
    string s;
    while(cin>>s)
    {
        if(s == "DONE") break;
        if(s == "DIST")
        {
            cin>>a>>b;
            int lca = LCA(a, b);
//            cout<<lca<<" "<<Cost[a]<<" "<<Cost[b]<<nl;
            ll ans = Cost[a] + Cost[b] - 2 * Cost[lca];
            cout<<ans<<nl;
        }
        else
        {
            cin>>a>>b>>k;
            int lca = LCA(a, b);
            if(L[a] - L[lca] + 1 == k)
                cout<<lca<<nl;
            else if(L[a] - L[lca] >= k)
            {
                int ans = findNode(a, k-1);
                cout<<ans<<nl;
            }
            else
            {
                k -= L[a] - L[lca];
                k--;
                int ans = findNode(b, (L[b]-L[lca] - k));
                cout<<ans<<nl;
            }
        }
    }
    cout<<nl;
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
