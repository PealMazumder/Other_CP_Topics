//Problem link: https://www.codechef.com/problems/WAV2
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int LB(vector<int>&ar, int tar)
{
    int l = 0, r = sz(ar), mid;
    while(l < r)
    {
        mid = (l + r) / 2;
        if(ar[mid] >= tar)
            r = mid;
        else l = mid + 1;
    }
    return l;
}
void solve()
{
    int n, q, x;
    cin>>n>>q;
    vector<int>ar(n);
    for(int i = 0; i<n; i++)
        cin>>ar[i];
    sort(all(ar));
    while(q--)
    {
        cin>>x;
        int id = LB(ar, x);

        if(id < n && ar[id] == x)
            cout<<"0\n";
        else if(id == n || (n - id) % 2 == 0)
            cout<<"POSITIVE\n";
        else cout<<"NEGATIVE\n";

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

