#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int N = 1e6 + 2;
int lps[N];
char s[N],p[N];
void kmpPreprocess(char *s)
{
	int len = strlen(s);
	lps[0] = 0;
	for(int i = 1, j = 0; i<len;)
	{
		if(s[i] != s[j])
		{
			if(j != 0)
				j = lps[j-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
		else
		{
			lps[i] = j+1;
			j++,i++;
		}
	}
}
int kmp(char *text, char *pattern)
{
	int j = 0,cnt = 0;
	int ps =  strlen(pattern);
	int sz = strlen(text);
	for(int i = 0; i<sz;)
	{	
		if(text[i] == pattern[j]) i++,j++;
		
		else
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
		if(j==ps)
		{
			cnt++;
		}
		//cout<<"cholche\n";
		
	}
	return cnt;
}
int main()
{
//	fast
	int t,casino = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",s,p);
		kmpPreprocess(p);
		int ans = kmp(s, p);
		printf("Case %d: %d\n",++casino,ans);
	}
    return 0;
}

