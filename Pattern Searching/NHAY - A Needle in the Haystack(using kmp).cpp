/*
	Problem Link: https://www.spoj.com/problems/NHAY/
*/

#include<bits/stdc++.h>
#define sz(c)						(int)c.size()
using namespace std;
const int INF = 0x7f7f7f7f;
const int modu = 1e9 + 7;
const int N = 1e6+1;
vector<int> lps;
void kmpPreprocess(string p, int len)
{
	for(int i = 0; i<len; i++) lps.push_back(0);
	
	for(int r = 1, l = 0; r<len; )
	{
		if(p[r] == p[l])
		{
			lps[r] = l + 1;
			r++,l++;
		}
		else
		{
			if(l == 0)
			{
				lps[r] = 0;
				r++;
			}
			else
				l = lps[l - 1];
		}
	}	
}
void kmp(string p, string t, int lnp)
{
	int len = (int) t.length();
	int cnt = 0;
	for(int i = 0, j = 0; i<len;)
	{
		if(t[i] == p[j])
		{
			i++,j++;
		}
		else
		{
			if(j != 0)
				j = lps[j - 1];
			else
				i++;
		}
		if(j == lnp)
		{
			printf("%d\n",i - j);
			cnt++;
		}
	}
	if(cnt == 0)
		printf("\n\n");
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		string pattern, text;
		cin>>pattern>>text;
		
		kmpPreprocess(pattern,n);
//		for(int i = 0; i<n; i++)
//			cout<<lsp[i]<<" ";
//		cout<<"\n";
		kmp(pattern,text,n);	
	}
    return 0;
}

