#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
using namespace std;
void solve()
{
	ll n;
	cin>>n;
	ll b = 8;
	ll res = 1;
	while(n)
	{
		if(n & 1)
			res = (res * b) % 10, n--;
		else
			b = (b * b) % 10, n /= 2;
	}
	cout<<res<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	solve();

	return 0;
}

