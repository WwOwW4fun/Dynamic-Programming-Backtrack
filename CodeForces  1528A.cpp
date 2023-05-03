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
#define membo(a) memset(a,false,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define fi first
#define se second
#define prq priority_queue
#define pb push_back

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define PI 3.1415926535897932385
#define INF 10000000

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
const int Max = 1e5;
vi adj[Max];
pii pi[Max];
ll n;
bool visited[Max];
ll l[Max];
ll r[Max];
void dfs(int u)
{
    visited[u] = true;
    pi[u].first = 0, pi[u].second = 0;
    for(ll v : adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
            pi[u].first += max(pi[v].first + abs(l[u] - l[v]),pi[v].second + abs(l[u] - r[v]));
            pi[u].second += max(pi[v].first + abs(r[u] - l[v]), pi[v].second + abs(r[u] - r[v]));
        }

    }
}
void input()
{
	cin >> n;
    for0(i,1,n+1)
    {
        ll x, y; cin >> x >> y;
        l[i] = x;
        r[i] = y;
    }
    for0(i,0,n - 1)
    {
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    membo(visited);
    dfs(1);
    cout << max(pi[1].first,pi[1].second) << endl;
}
int main()
{
    fastio;
    int tc;cin >> tc;
    while(tc --)
    {
        input();
        for0(i,1,n + 1) adj[i].clear();
    }

}
	