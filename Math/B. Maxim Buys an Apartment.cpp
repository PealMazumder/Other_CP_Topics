//Problem Link: https://codeforces.com/contest/854/problem/B
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
void solve()
{
    int n, k;
    cin>>n>>k;
    int in = (n+1)/3;///added an extra apartment
    int mn = 1;
    if(k == n || k == 0)
    {
        cout<<"0 0\n";
        return;
    }
    if(k == in)
    {
        int tm = in*3 - 1;/// (-1 means) exclude the extra apartment
        if(n-tm > 1)
            in += 1;
        cout<<mn<<" "<<n-in<<nl;
    }
    else if(k < in)
    {
        int tm = in*3 - 1;
        in += 2*(in-k);
        in += (n - (tm+1));
        cout<<mn<<" "<<n-in<<nl;
    }
    else
    {
        in += (k-in);
        cout<<mn<<" "<<n-in<<nl;
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


