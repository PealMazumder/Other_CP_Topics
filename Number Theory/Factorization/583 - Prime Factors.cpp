//Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(ll n)
{
	ll cn = abs(n);
	vector<ll> fac;
	for(ll i = 2; i*i<=cn; i++)
	{
		if(cn%i == 0)
		{
			while(cn%i == 0)
			{
				fac.push_back(i);
				cn /= i;
			}
		}
	}
	if(cn>1LL) fac.push_back(cn);
	if(n<0LL)
	{
		printf("%lld = -1",n);
		for(ll x : fac)
			printf(" x %lld",x);
		printf("\n");
	}
	else
	{
		printf("%lld = %lld",n,fac[0]);
		for(int i = 1; i<(int)fac.size(); i++)
			printf(" x %lld",fac[i]);
		printf("\n");
	}
}

int main()
{
	ll n;
	while(scanf("%lld",&n),n)
	{
		solve(n);
	}
}
