#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define mod 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define debug(x) cout<<(#x)<<" is "<<(x)<<endl
#define lb(arr,n,x) lower_bound(arr,arr+n,x)-arr
#define ub(arr,n,x) upper_bound(arr,arr+n,x)-arr
#define endl "\n"
#define PI 3.14159265358979323846  /* pi */
#define sqr(x) (x)*(x)
#define sign(x) (x>0)-(x<0)
#define is_poweroftwo(n) (n&& !(n&(n-1)))
#define all(v)  ((v).begin()),((v).end())
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0) // Converts degrees to radians.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI) // Converts radians to degrees.
#define int long long
#define debug(x) cout<<(#x)<<" is "<<(x)<<endl
#define AagLgaDe ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef long double ld;
 
//Calculation of (x^y)%mm
ll mod_exp(ll x,ll y,ll mm)
{
    if(y==0)
        return(1);
    else if(y%2==0)
        return(mod_exp((x*x)%mm,y/2,mm));
    else
        return((x*mod_exp((x*x)%mm,(y-1)/2,mm))%mm);
}
bool isPowerOfTwo(int n) 
{ 
   if(n==0) 
   return false;
   return (ceil(log2(n)) == floor(log2(n))); 
}
 
//int x1[]={+1,-1,+0,+0};
//int y1[]={+0,+0,+1,-1};
//int x2[]={+0,+0,+1,-1,-1,+1,-1,+1};
//int y2[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int x3[]={-2,-2,-1,-1,+1,+1,+2,+2};
//int y3[]={-1,+1,-2,+2,-2,+2,-1,+1};
 
int solve()
{
	int n, W;
	cin>>n>>W;
	vector<vector<int>> items(n, vector<int>(2));
	for(int i=0;i<n;i++){
		cin>>items[i][0]>>items[i][1];
	}
	sort(items.begin(), items.end());
	vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
	for(int j=1;j<=W;j++)
	{
		if(j>=items[0][0])
			dp[1][j]=items[0][1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(j>=items[i-1][0])
			{
				dp[i][j]=max(dp[i-1][j-items[i-1][0]]+items[i-1][1], dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][W];
 
}
 
signed main() {
  	AagLgaDe
    //int t;cin>>t;while(t--)
	    cout<<solve()<<endl;
 
 
return 0;
}