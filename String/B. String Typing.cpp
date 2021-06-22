//Problem Link: https://codeforces.com/contest/954/problem/B
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mid = n/2;
    int ans = 0;
    while(mid > 0)
    {
        if(s.substr(0, mid) == s.substr(mid, mid))
        {
            ans += mid + 1;
            break;
        }
        mid--;
    }
    ans += n - 2*mid;
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


