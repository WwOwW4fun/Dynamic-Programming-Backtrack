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

const int Max = 2e5 + 7;
int dp[Max];
int k[Max];
int d[Max];
 
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k[i];
    }
    for (int i = 0; i < n; i++){
        d[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++){
        int l = 0, r = n - 1;
        while (l <= r){
            int mid = (l + r)/2;
            if (d[mid] < k[i]){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        dp[i] = l;
        d[l] = k[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        res = max(res, dp[i]);
    }
    cout << res + 1;
}