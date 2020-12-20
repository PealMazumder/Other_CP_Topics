//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1224
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int casino = 0, ans = 0;
struct node
{
	int cnt;
	node * next[4];
	node()
	{
		cnt = 0;
		for(int i = 0; i<4; i++)
			next[i] = NULL;
	}
} * root;
void insert(char* str, int len)
{
	node* curr = root;
	for(int i = 0; i<len; i++)
	{
		int id;
		if(str[i] == 'A') id = 0;
		else if(str[i] == 'C') id = 1;
		else if(str[i] == 'G') id = 2;
		else id = 3;
		
		if(curr->next[id] == NULL)
			curr->next[id] = new node();
		
		curr = curr->next[id];
		curr->cnt++;
		ans = max(ans, (curr->cnt) * (i+1));	
	}
}
void del(node* curr)
{
	for(int i = 0; i<4; i++)
		if(curr->next[i])
			del(curr->next[i]);
	delete(curr);
}
void solve()
{
	root = new node();
	int n;
	scanf("%d", &n);
	char s[50];
	ans = 0;
	for(int i = 0; i<n; i++)
	{
		scanf("%s", s);
		insert(s, strlen(s));
	}
	del(root);
	printf("Case %d: %d\n", ++casino, ans);
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);
	
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}


