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
const int Max = 1000;
char a[Max][Max];
int path(int n){
	int f[n+1][n+1];
    for(int  i=0;i<=n;i++)
	{
    	for(int j=0;j<=n;j++)
    	{
    		if(i==0||j==0)f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j==1&&a[i-1][j-1]!='*') f[i][j]=1;
			else if(a[i-1][j-1]=='*') f[i][j]=0;
			else f[i][j]=f[i-1][j]+f[i][j-1];
			f[i][j]%=(int)(1e9+7);
		}
	}
	return f[n][n]%(int)(1e9+7);
}
int main(){
	int n; cin >> n;
	for(int i = 0; i < n;i ++)
	{
		for(int j = 0 ;j < n ;j++)
		{
			cin >>a[i][j];
		}
	}
	cout << path(n);
}