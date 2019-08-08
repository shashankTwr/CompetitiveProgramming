#include <bits/stdc++.h>
using namespace std;
int uglyNumber(int n){
	vector<int> dp(n);
	int i2=0,i3=0,i5=0;
	int nextMul2=2,nextMul3=3,nextMul5=5;
	dp[0]=1;
	int next_ugly_number=1;
	for(int i=1;i<n;i++){
		next_ugly_number=min(nextMul2,min(nextMul3,nextMul5));
		dp[i]=next_ugly_number;
		if(next_ugly_number == nextMul2){
			i2=i2+1,nextMul2=dp[i2]*2;
		}
		if(next_ugly_number == nextMul3){
			i3=i3+1,nextMul3=dp[i3]*3;
		}
		if(next_ugly_number == nextMul5){
			i5=i5+1,nextMul5=dp[i5]*5;
		}
	}
	return next_ugly_number;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int x=uglyNumber(n);
	cout<<x;
	return 0;
}