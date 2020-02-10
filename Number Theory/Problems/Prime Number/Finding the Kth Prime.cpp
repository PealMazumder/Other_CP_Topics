///https://www.spoj.com/problems/TDKPRIME/
#include<bits/stdc++.h>

using namespace std;
const int N = 87000008;
bool isPrime[N];
vector<int> v;
void sieve()
{
	isPrime[0] = isPrime[1] = true;
	
	for(int i = 2; i*i <= N; i++)
	{
		if(!isPrime[i])
		{
			for(int j = i*i; j <= N; j += i)
			{
				isPrime[j] = true;
			}
		}
	}
	for(int i = 2; i <= N; i++)
	{
		if(!isPrime[i])
			v.push_back(i);
	}
}

int main()
{
	sieve();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",v[k-1]);
	}

    return 0;
}

