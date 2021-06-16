//Problem Link: https://codeforces.com/problemset/problem/990/C
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
    unordered_map<int , int> a, b;
    string s;
    ll ans = 0, cnt = 0;
    while(n--)
    {
        cin>>s;
        int ss = sz(s);
        if(s[0] == ')' && s[ss-1] == '(')
            continue;
        deque<char> dq;
        bool ck = false;
        for(int i = 0; i<sz(s); i++)
        {
            if(!dq.empty() && dq.back() == '(' && s[i] == ')')
                dq.pop_back();
            else dq.push_back(s[i]);
            if(sz(dq) > (ss+1/2)) {ck = true; break;}
        }
        if(ck) continue;
        if(dq.empty())
            cnt++;
        else if(dq.front() == ')' && dq.back() == '(')
            continue;
        else if(dq.front() == '(')
            a[sz(dq)]++;
        else b[sz(dq)]++;
    }
    ans += (cnt*(cnt-1)) + cnt;
//    cout<<ans<<nl;

    for(auto it : a)
        ans += it.second *1LL* b[it.first];
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

