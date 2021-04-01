//Problem Link: https://lightoj.com/problem/crossed-ladders
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()
double err = 1e-8;
using namespace std;
int casino = 0;
void solve()
{
	double x, y, c;
	scanf("%lf%lf%lf", &x, &y, &c);
	double l = 1, r = min(x, y);
	int cnt = 0;
	while(r-l > err && cnt < 100)
	{
		cnt++;
		double d = (l + r)/2;
		double tm = 1.0/((1.0/sqrt(x*x-d*d)) +(1/sqrt(y*y - d*d)));
		if(c < tm)
			l = d;
		else r = d;
	}
	printf("Case %d: %.10lf\n", ++casino, l);
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}

