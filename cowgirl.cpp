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
int n;
int f[100][100];
bool check(int x,int y){
	for(int i = 1; i < n;i++)
	{
		int a=(x>>i)&1, b=(x>>(i-1))&1;
		int c=(y>>i)&1, d=(y>>(i-1))&1;
		if(a==b&&b==c&&c==d) return 0;
	}
	return 1;
}
int main(){
	int t; cin >> t;
	while(t--)
	{
	
	int m; cin >> n >> m;
	if(n>m) swap(m,n);
	for(int i = 0;i <=(1<<n)-1;i++)
	{
		f[1][i]=1;
	}
	for(int i =2 ;i <=m;i++)
	{
		for(int mark=0;mark<=(1<<n)-1;mark++)
		{
			f[i][mark]=0;
			for(int mark2=0;mark2<=(1<<n)-1;mark2++)
			{
				if(check(mark,mark2)) f[i][mark]+=f[i-1][mark2];
			}
		}
	}
	unsigned long long res =0;
	for(int i =0;i<=(1<<n)-1;i++)
	{
		res+=f[m][i];
	}
    cout << res << endl;
	}
}