#include<bits/stdc++.h>
#define ll long long

using namespace std;
int casino = 0;
void solve()
{
	ll p,l;
	scanf("%lld %lld",&p, &l);
	ll n = p - l;
	vector<ll> div;
	for(ll i = 1; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			if(n/i == i && i>l)
				div.push_back(i);
			else
			{
				if(i>l) div.push_back(i);
				if(n/i> l) div.push_back(n/i);
			}
		}
	}
	sort(div.begin(), div.end());
	printf("Case %d:",++casino);
	if(div.empty())
		printf(" impossible\n");
	else
	{
		for(ll x : div)
			printf(" %lld",x);
		printf("\n");
	}
		
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
