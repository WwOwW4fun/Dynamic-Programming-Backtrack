#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(int it : v)
#define reset(a) memset(a,0,sizeof(a))
#define mem(a) memset(a,-1,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define fi first
#define se second
#define prq priority_queue

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
ll n;
const int Max = 1e3;
ll a[4][Max];
ll dp[4][1 << 13][Max]; // to store the maximum number of problems have been solved
void input()
{
	cin >> n;
	for0(i,0,3)
	{
		for0(j,1,n + 1)
		{
			cin >> a[i][j];
		}
	}
}
/* p is the candidate just solved a problem
 bitmask is to note the problems have been solved 
time is the remaning time*/
int solve(int p, int bitmask, int time)
{
	if(dp[p][bitmask][time] > -1) return dp[p][bitmask][time]; // if the dp[p][bitmask][time] have already been caculated -> return the value of it
	if(time == 0) return 0;
	if(bitmask == (1 << n) - 1) return 0;
	int ans = 0;
	for0(i,0,3)
	{
		if(i == p) continue;
		for0(j,1,n + 1)
		{
			if(!((bitmask >> (j - 1)) & 1) and time >= a[i][j])
			{
				int x = bitmask;
				ans = max(ans,solve(i,x |(1 << (j - 1)), time - a[i][j]) + 1);
			}
		}
	}
	dp[p][bitmask][time] = ans;
	return ans;
}
void write()
{
	mem(dp);
	cout << max({solve(0,0,280), solve(1,0,280),solve(2,0,280)}) << endl;
}
signed main()
{
	fastio;
	int tc; cin >> tc;
	while(tc--)
	{
		input();
		write();
	}
	
}