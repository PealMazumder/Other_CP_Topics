/*
	Video Tutorials on KMP : 
			https://www.youtube.com/watch?v=sMARZCTPyNI(Bangla)
			https://www.youtube.com/watch?v=GTJr8OvyEVQ
			https://www.youtube.com/watch?v=KG44VoDtsAA
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int modu = 1e9 + 7;
const int N = 1e6+1;
int lps[N];
void build_lps(char *p, int len)
{
	
	lps[0] = 0;
	
	for(int i = 1,j = 0; i<len;)
	{
		if(p[i] == p[j])
		{
			lps[i] = j+1;
			j++,i++;
		}
		else
		{
			if(j == 0)
			{
				lps[i] = 0;
				i++;
			}
			else
				j = lps[j-1];
		}
	}
}

int kmp(char *s, char *p, int len)
{
	int j = 0, cnt = 0;
	for(int i = 0; i<len;)
	{
		if(s[i] == p[j]) i++, j++,cnt++;
		else
		{
			cnt = lps[j - 1];
			if(j == 0) i++;
			else j = lps[j - 1];
		}
	}
	int dif = len - cnt;
//	cout<<dif<<" "<<len<<" "<<cnt;
	return dif + len;
}
int main()
{
//	fast
	int t,casino = 0;
	scanf("%d",&t);
	while(t--)
	{
		char s[N],p[N];
		scanf(" %s",s);
		int len = strlen(s);
		reverse_copy(s, s+len, p);
		build_lps(p,len);
		int ans = kmp(s,p,len);
		printf("Case %d: %d\n",++casino,ans);
	}
    return 0;
}

