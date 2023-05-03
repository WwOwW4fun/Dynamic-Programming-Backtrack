/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
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
const int Max = 210;
ll n;
vector<int> adj[Max];
bool check[Max][2];
int solve(int u, int m)
{
	int temp = m;
	for(int v : adj[u])
	{
		if(m == 0)
		{
			int x = solve(v,0), y = solve(v,1);
			temp += max(x,y);
			if(x == y) check[u][m] =  true;
			if(x > y and check[v][0]) check[u][m] = true;
			if(x < y and check [v][1]) check[u][m] = true;
		}
		else
		{
			temp += solve(v,0);
			if(check[v][0]) check[u][m] = true; 
		}
	}
	return temp;
}
void input()
{
	map <string , int> mp;
	string s; cin >> s;
	int t = 1;
	mp[s] = t;
	int x = n - 1;
	while(x --)
	{
		string s1,s2; cin >> s1 >> s2;
		if(mp[s1] == 0) mp[s1] = ++t;
		if(mp[s2] == 0) mp[s2] = ++t;
		int u = mp[s1], v = mp[s2];
		// adj[u].push_back(v);
		adj[v].push_back(u);
		//cout << u << " " << v << endl;
	}
	ll temp1 = solve(1,1);
	ll temp0 = solve(1,0);
	ll ans  = max(temp1,temp0);
	cout << ans << " ";
	cout << (((temp0 <  temp1 and !check[1][1]) || (temp1 < temp0 and !check[1][0])) ? "Yes" : "No") << endl;
	for0(i,0,Max) adj[i].clear();
	for0(i,0,Max)
	{
		for0(j,0,2) check[i][j] = false;
	}
		}
int main()
{
	while(cin >> n and n)
		input();
}