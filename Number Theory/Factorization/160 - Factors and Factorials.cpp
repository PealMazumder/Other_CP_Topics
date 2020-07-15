#include<bits/stdc++.h>
#define 	FO			freopen("output.txt", "w", stdout);
using namespace std;
void solve(int n)
{
	int ar[105] ={0};
	for(int i = 2; i<=n; i++)
	{
		int ii = i;
		for(int j = 2; j*j<=ii; j++)
		{
			if(ii%j == 0)
			{
				while(ii%j == 0)
				{
					ar[j]++;
					ii/=j;
				}
			}
		}
		if(ii>1)ar[ii]++;
	}
	vector<int> ans;
	for(int i = 2; i<101; i++)
		if(ar[i]>0) ans.push_back(ar[i]);
	sort(ans.begin(),ans.end(),greater<int>());
	printf("%3d! =",n);
	int cnt = 0;
	for(int x : ans)
	{
		cnt++;
		if(cnt > 15) 
		{
			cnt -= 15;
			printf("\n      ");
		}
		printf("%3d",x);
	}
	printf("\n");
}
int main()
{
//	FO
	int n;
	while(scanf("%d",&n),n)
	{
		solve(n);
	}
	return 0;
}
