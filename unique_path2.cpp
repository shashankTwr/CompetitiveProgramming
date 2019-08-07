#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m=obstacleGrid[0].size(),n=obstacleGrid.size();
  if(m==0 || n==0) return 1;
  int dp[n][m];
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(i!=0 || j!=0){
              if(i-1 >=0 && obstacleGrid[i-1][j]==0){
                  dp[i][j]+=dp[i-1][j];
                  //cout<<dp[i-1][j]<<"i-1  ";
              }
              if(j-1>=0 && obstacleGrid[i-1][j]==1){
                  dp[i][j]+=dp[i][j-1];
                  //cout<<j-1<<" j-1 "<<dp[i][j-1];
              }
              //cout<<"\n";
          }
      }
  }
  return dp[n-1][m-1];
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