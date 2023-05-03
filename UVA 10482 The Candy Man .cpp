#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(auto it : v)
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
#define PI 3.1415926535897932385
#define INF 10000000

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
int t;
ll n;
const int Max = 650;
ll a[Max];
ll dp[35][Max][Max];
ll sum;
void input()
{
	cin >> n;
	sum = 0;
	for0(i,0,n)
	{
		cin >> a[i]; sum += a[i];
	}
	for0(t,0,n + 1)
	{
		for0(i,0,sum + 1)
		{
			for0(j,0,sum + 1) dp[t][i][j] = -1;
		}
	}
	
}
ll solve(int i, ll x, ll y)
{
	if(i == n) 
	{
		ll z = sum - x - y;
		return max({x,y,z}) - min({x,y,z}); 
	}		
	if(dp[i][x][y] > -1) return dp[i][x][y];
	dp[i][x][y] = min({solve(i + 1,x + a[i],y),solve(i + 1,x, y + a[i]),solve(i + 1,x,y)});
	return dp[i][x][y];
}
void write()
{
	cout << "Case " << ++t << ": ";
	cout << solve(0,0,0) << endl;
}
int main()
{
	fastio
	t = 0;
	int tc; cin >> tc;
	while(tc --)
	{
		input();
		write();
	}
}