/*
  Problem Link: https://codeforces.com/contest/1213/problem/B
  
  N.B:- This problem can be solved variously, but to practice basic Stack Data structure,
  		you can solve this problem using stack.
*/

#include<bits/stdc++.h>
#define	fast						ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define rep(i,n)						for(int i = 1; i<=n; i++)
#define all(p)						p.begin(),p.end()
#define	mem(ar,val)					memset(ar, val, sizeof(ar))
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define mkp(x,y)					make_pair(x,y)
#define SS(a,b)						scanf("%lld%lld",&a,&b)
#define SSS(a,b,c)						scanf("%lld%lld%lld",&a,&b,&c)
#define S(a)						scanf("%lld",&a)
#define PP(a,b)						printf("%lld %lld\n",a,b)
#define PPP(a,b,c)						printf("%lld %lld %lld\n",a,b,c)
#define P(a)						printf("%lld\n",a)
#define ff						first
#define ss						second
#define gap                     <<" "<<
#define ll						long long
#define nl						"\n"
#define MAX(a, b)					((a) > (b) ? (a) : (b))
#define MIN(a, b)					((a) < (b) ? (a) : (b))
#define FI						freopen("input.txt", "r", stdin);
#define FO						freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int modu = 1e9 + 7;
const int N = 1e6+7;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ar[n+1];
		for(int i = 1; i<=n; i++)
		{
			scanf("%d",&ar[i]);
		}
		int ans = 0;
		stack<int> st;
		st.push(ar[1]);
		for(int i = 2; i<=n; i++)
		{
			int tm = st.top();
			if(tm>ar[i])
			{
				st.pop();
				ans++;
				if(!st.empty())
					tm = st.top();
				vector<int> v;
				while(true)
				{
					if(st.empty()) break;
					else if(tm>ar[i])
						ans++;
					else
						v.pb(tm);
					st.pop();
					if(!st.empty())
						tm = st.top();
				}
				for(int y : v)
					st.push(y);
			}
			st.push(ar[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}


