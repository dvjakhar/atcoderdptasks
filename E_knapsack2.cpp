#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
struct objects{
    int weight,value;
};
ll solve(){
   int n,w;
   cin>>n>>w;
   objects object[n];
   int totalvalue=0;
   for(int i=0;i<n;i++){
       cin>>object[i].weight>>object[i].value;
       totalvalue+=object[i].value;
   }
   ll dp[n+1][totalvalue+1];
    //dp[i][j] denotes the least weight to get a value of
   // j from the first i objects
   dp[0][0]=0;//It takes 0 weight here
   int ans=0;
   for(int i=1;i<=totalvalue;i++){
       dp[0][i]=1e18;
      // Just set it arbitrarily large
       //because it's not possible 
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<=totalvalue;j++){
           if(j>=object[i].value){
                dp[i+1][j]=min(dp[i][j],dp[i][j-object[i].value]+object[i].weight);
                //Either don't choose this object(dp[i][j]) or choose this object
                //The value without it would be j-object[i].value
                //the minimum weight would be the minimum weight needed to
                //get a value of j- object[i].value and add the weight of this object.
           }
           else{
               //If I choose this object the value will go over j
               dp[i+1][j]=dp[i][j];
           }
           if(dp[i+1][j]<=w){//Is it possible to get value of j in less than w weight
               ans=max(ans,j);//Find maximum such j
           }
       }
   }
   return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}
