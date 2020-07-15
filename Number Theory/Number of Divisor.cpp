#include<bits/stdc++.h>
using namespace std;
int NOD(int n)
{
	int ret = 1;
	for(int i = 2; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			int cnt = 1;
			while(n%i == 0)
			{
				cnt++;
				n/=i;
			}
			ret *= cnt;
		}
	}
	if(n>1)
		ret *= 2;
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("Number of Divisor of %d is : ",n);
	printf("%d\n",NOD(n));
	return 0;
}
