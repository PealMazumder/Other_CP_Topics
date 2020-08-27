//Problem Link: https://codeforces.com/contest/118/problem/D
#include<bits/stdc++.h>
#define	mod	100000000
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const ll INF = 0x7f7f7f7f;
int numF, numH;
int dp[101][101][11][11];
int numArrangements(int n1, int n2, int k1, int k2)
{
	if((n1 + n2) == 0) return 1;
	if(dp[n1][n2][k1][k2] != -1) return dp[n1][n2][k1][k2];
	int x = 0;
	if(n1 > 0 && k1 > 0)
		x = numArrangements(n1-1, n2, k1 - 1 , numH);
	int y = 0;
	if(n2 > 0 && k2 > 0)
		y = numArrangements(n1, n2 - 1, numF, k2 - 1);
		
	return dp[n1][n2][k1][k2] = (x + y) % mod;
}
void solve()
{
	int n1, n2;
	cin>>n1>>n2>>numF>>numH;
	mem(dp, -1);
	int ans = numArrangements(n1, n2, numF, numH);
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	solve();

	return 0;
}

