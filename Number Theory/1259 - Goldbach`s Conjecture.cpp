///Problem Link: http://lightoj.com/volume_showproblem.php?problem=1259
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int N = 10000002;
bool vis[N];
int casino = 0;
vector<int> prime;
void sieve()
{
	for(int i = 3; i*i <= N; i += 2)
	{
		if(vis[i] == 0)
		{
			for(int j = i*i; j<N; j += 2*i)
				vis[j] = 1;
		}
	}
	prime.pb(2);
	for(int i = 3; i<N; i += 2)
		if(vis[i] == 0)
			prime.pb(i);
}
void solve()
{
	int n, cnt = 0, tm;
	scanf("%d",&n);
	for(int i = 0; i<sz(prime) && prime[i] <= n/2; i++)
	{
		tm = n-prime[i];
		if(vis[tm] == 0 && (tm & 1) || tm == 2)
			cnt++;	
	}
	printf("Case %d: %d\n", ++casino, cnt);
}
int main()
{
	sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();	
	}
	return 0;
}
