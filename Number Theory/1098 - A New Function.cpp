#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const ll INF = 0x7f7f7f7f;
int casino = 0;
void solve()
{
	ll n, ans = 0;
	cin>>n;
	cout<<"Case "<<++casino<<": ";
	for(ll i = 2, j; i*i<=n; i++)
	{
		j = n/i;
		ans += (j*(j+1)/2 - i*(i-1)/2);
		ans += (j-i) * i;
	}
	cout<<ans<<nl;
}
int main()
{	
	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}

