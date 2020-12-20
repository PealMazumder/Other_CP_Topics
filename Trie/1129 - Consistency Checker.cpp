//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1129
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int casino = 0;
struct node{
	bool endmark;
	node* next[11];
	node(){
		endmark = false;
		for(int i = 0; i<10; i++){
			next[i] = NULL;
		}
			
	}
}*root;
bool insert(char* str, int len)
{
	node* curr = root;
	bool ck = false;
	for(int i = 0; i<len; i++){
		ck = false;
		int id = str[i] - '0';
		if(curr->next[id] == NULL)
		{
			curr->next[id] = new node();
			ck = true;
		}
		curr = curr->next[id];
		if(curr->endmark)
			return true;
	}
	curr->endmark = true;
	if(ck == false) return true;/// if current string is already available in trie tree
	return false;
}
void del(node* curr)
{
	for(int i = 0; i<10; i++)
		if(curr->next[i])
			del(curr->next[i]);
	delete(curr);
}
void solve()
{
	int n;
	scanf("%d", &n);
	char s[11];
	bool ans = false;
	root = new node();
	while(n--)
	{
		scanf("%s", s);
		bool ck = insert(s, strlen(s));
		if(ck) ans = true;
	}
	del(root);
	if(ans)
		printf("Case %d: NO\n", ++casino);
	else
		printf("Case %d: YES\n", ++casino);
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}


