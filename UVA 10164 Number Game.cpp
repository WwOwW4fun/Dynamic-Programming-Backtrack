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

const int Max = 5e3;
ll n;
ll a[Max];
ll ans[Max];
bool check;
void backtrack(ll num, ll sum, ll pos)
{
	if(pos > 2*n - 1) return;
	if(num > n) return;
	if(check) return;
	if(sum % n == 0 and num == n)
	{
		check = true;
		cout << "Yes" << endl;
		for0(i,0,n - 1) cout << ans[i] << " ";
		cout << a[pos - 1] ;
		cout << endl;
		return;
	}
	ans[num] = a[pos];
	backtrack(num + 1, sum + a[pos], pos + 1);
	backtrack(num,sum,pos + 1);
}
void input()
{
	while(cin >> n and  n)
	{
		for0(i,0,2*n - 1) cin >> a[i];
		check = false;
		backtrack(0,0,0);
		if(!check) cout << "No" << endl;
	}
	
	
}
int main()
{
	input();
}