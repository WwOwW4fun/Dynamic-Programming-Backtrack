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

const int mod = 1000000007;
int n, m;
int visited[200][20][4000];
int solve(int id, int last, int bitmask)
{
    if(id >= m) return 0;
    if(visited[id][last][bitmask] != -1) return visited[id][last][bitmask];
    int ans = 0;
    if(bitmask == (1 << n) - 1) ans++;
    for(int i = last - 1; i <= last + 1; i += 2)
    {
        if(i < 0 || i >= n) continue;
       ans += solve(id + 1, i, bitmask | (1 << i));
       ans %= mod;
    }
    visited[id][last][bitmask] = ans;
    return ans;
}
void input()
{
    cin >> n >> m;
    memset(visited,-1,sizeof(visited));
    ll res = 0;
    for0(i,1,n)
    {
      res += solve(0,i,(1 << i));
      res %= mod;
    }
    cout << res << endl;
}
int main()
{
    int tc; cin >> tc;
    while(tc --)
        input();
}