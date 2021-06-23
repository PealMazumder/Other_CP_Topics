//Problem Link: https://codeforces.com/contest/1066/problem/C
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
void solve()
{
   ll q;
   cin>>q;
   ll l = 0, r = 0, id;
   char ch;
   map<ll, pair<pair<ll, ll>, char> > mp;
   cin>>ch>>id;
   mp[id] = {{0, 0}, 'L'};
   q--;
   ll preL = id, preR = id;
   while(q--)
   {
       cin>>ch>>id;
       if(ch == 'L')
       {
            l++;
            mp[id] = {{l, mp[preL].ff.ss + 1}, 'L'};
            preL = id;
       }
       else if(ch == 'R')
       {
           r++;
           mp[id] = {{mp[preR].ff.ff + 1, r}, 'R'};
           preR = id;
       }
       else
       {
            ll ansL, ansR;
            if(mp[id].ss == 'L')
            {
                ansL = l - mp[id].ff.ff;
                ansR = r + mp[id].ff.ss;
            }
            else
            {
                ansL = l + mp[id].ff.ff;
                ansR = r - mp[id].ff.ss;
            }

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
