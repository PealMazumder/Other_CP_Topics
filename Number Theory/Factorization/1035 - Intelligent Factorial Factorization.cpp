//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1035
#include<bits/stdc++.h>
#define	nl	"\n"
using namespace std;
int casino = 0, n;
void primeFact(int n)
{
	map<int, int> mp;
	for(int i = 2; i <= n; i++)
	{
		int tm = i;
		for(int j = 2; j * j <= tm; j++)
		{
			if(tm % j == 0)
			{
				int cnt = 0;
				while(tm>0 && tm % j == 0)
				{
					cnt++;
					tm /= j;
				}
				mp[j] += cnt;
			}
		}
		if(tm>1)
			mp[tm]++;
	}
	cout<<"Case "<<++casino<<": "<<n<<" = ";
	bool ck = false;
	for(auto it : mp)
	{
		if(ck == false)
		{
			cout<<it.first<<" ("<<it.second<<")";
			ck = true;
		}
		else
			cout<<" * "<<it.first<<" ("<<it.second<<")";
		
	}
	cout<<"\n";
	return;
}
void solve()
{
	cin>>n;
	primeFact(n);
	return;
}
int main()
{
//	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	    solve();
	return 0;
}

