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
int ans;
char a[20];
void backtrack(int cnt)
{
    ans= min (cnt,ans);
    for0(i,0,12)
    {
        if(a[i] == 'o')
        {
            if(i >= 2 and  a[i-1] == 'o' and a[i-2] == '-')
            {
                a[i-2] = 'o'; a[i - 1] = '-' ; a[i] = '-';
                backtrack(cnt-1);
                a[i-2] = '-'; a[i-1] = 'o';a[i] = 'o';
            }
            if(i <= 9 and  a[i+1] == 'o' and a[i+2] == '-')
            {
                a[i+2] = 'o'; a[i+1] = '-' ; a[i] = '-';
                backtrack(cnt-1);
                a[i+2] = '-'; a[i+1] = 'o' ; a[i] ='o';
            }
        }
    }
}
int main()
{
    int n; cin >> n;
    while(n--)
    {
        int number = 0;
        for0(i,0,12)
        {
            cin >> a[i];
            if(a[i] == 'o')
            {
                number++;
            }
        }
        ans = INT_MAX;
        backtrack(number);
        cout << ans << endl;

    }
}
