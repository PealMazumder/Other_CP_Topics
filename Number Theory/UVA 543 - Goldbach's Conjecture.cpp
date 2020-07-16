#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
bool flag[N];
void sieve()
{
	flag[0] = flag[1] =  true;
	for(int i = 4; i<=N; i+=2)
		flag[i] = true;
	for(int i = 3; i*i<=N; i+=2)// avoiding even numbers
		if(!flag[i])
		{
			for(int j = i*i; j<=N; j += 2*i) // avoiding even multiples
				flag[j] = true;
		}
}
void findPairs(int n)
{
	for(int i = 3; i<=n/2; i++)
	{
		if(!flag[i] && !flag[n-i])
		{
			printf("%d = %d + %d\n",n, i, n-i);
			return;	
		}	
	}
	printf("Goldbach's conjecture is wrong.\n");
}
int main()
{
	sieve();
	int n;
	while(scanf("%d",&n),n)
	{
		findPairs(n);
	}
	return 0;
}
