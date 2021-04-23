//Problem Link: https://codeforces.com/contest/1512/problem/E
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
void solve()
{
    int n, l, r , s;
    cin>>n>>l>>r>>s;
    int x = r - l + 1;
    int ar[x];
    int sum = 0;
    for(int i = 1; i <= x; i++)
    {
        ar[i-1] = i;
        sum += i;
        if(sum == s && i != x || sum > s)
        {
            cout<<"-1\n";
            return;
        }
    }
    int y = n;
    for(int i = x-1; i >= 0; i--)
    {
        if(sum == s || y == 0)break;
        int dif = y - ar[i];
        int need = s - sum;
        if(dif <= need)
            sum += dif, ar[i] += dif, y--;
        else sum += need, ar[i] += need;
    }
    if(sum != s)
    {
        cout<<"-1\n";
        return;
    }
    unordered_map<int, bool> mp;
    for(int i = 0; i<x; i++)
        mp[ar[i]] = 1;
    int j = 1;
    for(int i = 1; i<l; i++, j++)
    {
        while(mp[j] != 0)
            j++;
        cout<<j<<" ";
    }
//    cout<<" first ";
    for(int i = 0; i < x; i++)
        cout<<ar[i]<<" ";
//     cout<<" mid ";
    for(int i = r+1; i<=n; i++)
    {
        while(mp[j] != 0)
            j++;
        cout<<j<<" ";
        j++;
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

 