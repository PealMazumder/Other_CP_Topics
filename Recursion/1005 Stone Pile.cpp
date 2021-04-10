//Problem Link: https://acm.timus.ru/problem.aspx?space=1&num=1005
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0, n;
int ar[25];
ll sum = 0, a, ans = INT_MAX;
void check(int pos, ll sm)
{
    if(pos >= n)
    {
        ans = min(ans, abs(sm - (sum - sm)));
//        cout<<ans<<nl;
        return;
    }
    check(pos+1, sm+ar[pos]);
    check(pos+1, sm);

}
void solve()
{
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>ar[i];
        sum += ar[i];
    }
    check(0, 0);
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
