#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return a.first>b.first && a.first == b.first && a.second > b.second;
  }
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s;
	cin>>n>>s;
	vector<pair<int,int> > dollar(n);
	for(int i=0;i<n;i++)
		cin>>dollar[i].first>>dollar[i].second;
	sort(dollar.begin(),dollar.end());
  if(dollar[0].first > s) cout<<"-1";
  else if(dollar[0].first == s){
    int temp;
    if(dollar[0].second>0) temp=-1;
    else temp=0;
    cout<<temp;
  }
  else{
    int ans;
    dollar[0].second!=0?ans=100-dollar[0].second:ans=0;
    for(int i=1;i<dollar.size();i++){
      if(s < dollar[i].first) break;
      else{
        int diff;
        if(dollar[i].first == s){
          if(dollar[i].second>0) diff=-1;
          else diff=0;
        }else dollar[i].second!=0?diff=100-dollar[i].second:diff=0;
        //cout<<diff<<"\t";
        ans=max(ans,diff);
      }
      //cout<<dollar[i].first<<"\t";
    }
    cout<<ans;
  }
  return 0;
}