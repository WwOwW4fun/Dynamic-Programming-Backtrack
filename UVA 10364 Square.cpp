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

bool visited[10000];
ll n;
int a[10000];
ll all;
bool solve(int start, ll sum, int number_edge)
{
    if(number_edge == 3) return true;
    else if(sum == all / 4)
    {
        if(solve(0,0,number_edge + 1)) return true;
    }
    for0(start,n)
    {
        if(!visited[i])
        {
            visited[i] = true;
            if(solve(i + 1, sum + a[i], number_edge) and sum + a[i] <= all / 4) return true;
            visited[i] = false;
        }
    }
    return false;
}
int main()
{
    int tc; cin >> tc;
    output;
    while(tc --)
    {
        output;
        memset(visited,false,sizeof(visited));
        cin >> n;
        all = 0;
        int maxx = INT_MIN;
        for0(0,n)
        {
            cin >> a[i];
            all += a[i];
            maxx = max(maxx,a[i]);
        }
        if(all % 4 != 0) cout << "no" << endl;
        else if(maxx > all / 4) cout << "no" << endl;
        else if(solve(0,0,0))
        {
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }
}