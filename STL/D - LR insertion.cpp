//https://atcoder.jp/contests/abc237/tasks/abc237_d
#include<bits/stdc++.h>
#define         nl                  "\n"
#define         mod                 1000000007
#define         sz(c)               (int)c.size()
#define         pb                  push_back
#define         ff                  first
#define         ss                  second
#define         ll                  long long
#define         all(p)              p.begin(),p.end()
using namespace std;
const ll INF = 1000000000000000000;
const int N = 1e6+7;

void solve()
{
   int n;
   string s;
   cin>>n>>s;

   deque<int> a, b;
   a.push_back(0);
   for(int i = 0; i<n; i++)
   {
       if(s[i] == 'L')
       {
           int tm = a.back();
           a.pop_back();
           a.push_back(i+1);
           b.push_back(tm);
       }
       else
           a.push_back(i+1);
   }
   for(auto it : a)
       cout<<it<<" ";
   while(!b.empty())
   {
       cout<<b.back()<<" ";
       b.pop_back();
   }
   cout<<nl;
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
