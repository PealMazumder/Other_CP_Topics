///https://www.codechef.com/problems/PRB01
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
	if(n==1) return false;
	
	for(int i = 2; i*i<=n; i++)
	{
		if(!(n%i)) return false;
	}
	
	return true;
		
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		bool ans = isPrime(n);
		if(ans)
			printf("yes\n");
		else
				printf("no\n");
	}
    return 0;
}

