///Problem Link: http://lightoj.com/volume_showproblem.php?problem=1215
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int casino = 0;
vector<ll> Divisors(ll n) 
{ 
    vector<ll> div; 
    for (ll i=1; i*i<=n; i++) 
    { 
        if ((n%i) == 0) 
        { 
            // If divisors are equal, take only one 
            if ((n/i )== i) 
                 div.push_back(i);
  
            else // Otherwise take both 
            {
            	div.push_back(i);
				div.push_back(n/i);	
			} 
        } 
    } 
    sort(div.begin(), div.end());
    return div;
}
ll gcd(ll a, ll b)
{
	while(b)
	{
		a = a%b;
		swap(a,b);
	}
	return a;
}
ll lcm(ll a, ll b)
{
	return (a/gcd(a,b))*b;
}
void solve()
{
	ll a, b, l;
	cin>>a>>b>>l;
	printf("Case %d: ", ++casino);
	if((l%a) !=0 || (l%b) != 0)
	{
		printf("impossible\n");
		return;
	}
	vector<ll> d = Divisors(l);
	for(ll x : d)
	{
		if(lcm(a, lcm(b, x)) == l)
		{
			printf("%lld\n", x);
			return;
		}
	}
	printf("impossible\n");
}
int main()
{
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();
	return 0;
}
