//Problem Link: https://cses.fi/problemset/task/2162/
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
    deque<int> dq;
    for(int i = 1; i<=n; i++)
        dq.push_back(i);
    while(!dq.empty())
    {
        int a = dq.front();
        dq.pop_front();
        if(dq.empty())
        {
            cout<<a<<nl;
            break;
        }
        else
        {
            cout<<dq.front()<<" ";
            dq.pop_front();
            dq.push_back(a);
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


