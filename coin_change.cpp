#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
            	cerr<<coins[j]<<"\t";
               if(i+coins[j] <= amount){
               	cerr<<i+coins[j]<<"\t";
                   if(dp[i]!=INT_MAX && dp[i]+1 <= dp[i+coins[j]]){
                       dp[i+coins[j]]=dp[i]+1;
                   }
               }
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,amount;
	cin>>n;
	vector<int> coins(n);
	for(int i=0;i<n;i++)
		cin>>coins[i];
	cin>>amount;
	cout<<coinChange(coins,amount)<<"\n";
}