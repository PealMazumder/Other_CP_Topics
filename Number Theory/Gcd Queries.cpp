//Problem Link : https://www.codechef.com/problems/GCDQ
#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
using namespace std;
ll a[100002], pre[100002], suf[100002];
ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
void solve()
{
	ll n, q, i, j, l, r;
	cin>>n>>q;
	for(i = 1; i<=n; i++)
		cin>>a[i];
	pre[0] = suf[n+1] = 0;
	for(i = 1; i<=n; i++)
		pre[i] = gcd(pre[i-1],a[i]);
	for(i = n; i>0; i--)
		suf[i] = gcd(suf[i+1],a[i]);
	while(q--)
	{
		cin>>l>>r;
		cout<<gcd(pre[l-1], suf[r+1])<<nl;
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}

