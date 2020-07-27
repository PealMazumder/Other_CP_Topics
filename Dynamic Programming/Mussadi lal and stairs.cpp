// Problem Link: https://www.codechef.com/problems/JAM11
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl "\n"
using namespace std;
const int N = 100007;
ll dp[N];
ll stairs(ll n)
{
	if(n<3)
		return n;
	else if(dp[n] != 0)
		return dp[n];
		
	dp[n] = (stairs(n-1) + stairs(n-2) + stairs(n-3)) % mod;
	
	return dp[n] % mod;
}
void solve()
{
	dp[3] = 4;
	ll n;
	cin>>n;
	cout<<stairs(n)<<nl;
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

