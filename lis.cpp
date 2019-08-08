#include <bits/stdc++.h>
using namespace std;
int lis(vector<int> a){
	vector<int> dp(a.size(),1);
	for(int i=1;i<a.size();i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && dp[j]+1 > dp[i]) dp[i]=dp[j]+1;
		}
	}
	return *max_element(dp.begin(),dp.begin()+dp.size());
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int x = lis(a);
	cout<<x;
	return 0;
}