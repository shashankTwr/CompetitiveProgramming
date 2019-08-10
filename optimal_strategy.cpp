#include <bits/stdc++.h>
using namespace std;
int helper(int start, int end, vector<int> &val, bool turn, vector<vector<vector<int> > > &dp)
{
  if(start == end-1){
    int res;
    if(turn) res=max(val[start],val[end]);
    else res=min(val[start],val[end]);
    dp[start][end][turn]=res;
  }
  if(dp[start][end][turn] != -1 ) return dp[start][end][turn];
  int res=0;
  if(turn==0) res=INT_MAX;
  if(turn) res = max(val[start]+helper(start+1,end,val,turn,dp),
    val[end-1]+helper(start,end-1,val,turn,dp));
  else res = min(helper(start+1,end,val,turn,dp),helper(start,end-1,val,turn,dp));
  dp[start][end][turn]=res;
  return res;
}
bool optimal_subset(vector<int>& val) {
  int sum=0;
  vector<vector<vector<int> > > dp(val.size(),vector<vector<int> >(val.size(),vector <int>(2,-1)));
  for(auto it:val) sum+=it;
  int A = helper(0, val.size()-1, val, 1, dp);
  cout<<A<<"\n";
  return A > (sum-A);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,amount;
	cin>>n;
	vector<int> val(n);
	for(int i=0;i<n;i++)
		cin>>val[i];
	int x=optimal_subset(val);
  cout<<x;
}