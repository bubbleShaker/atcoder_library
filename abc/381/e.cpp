#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<int> slash;
  for(int i=0;i<n;i++){
    if(s[i]=='/'){
      slash.push_back(i+1);
    }
  }
  vector<int> rsw_one(n+2),rsw_two(n+2);
  for(int i=0;i<n;i++){
    if(s[i]=='1'){
      rsw_one[i+1]=rsw_one[i]+1;
    }else{
      rsw_one[i+1]=rsw_one[i];
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='2'){
      rsw_two[i+1]=rsw_two[i+2]+1;
    }else{
      rsw_two[i+1]=rsw_two[i+2];
    }
  }
  while(q--){
    int ans=0;
    int l,r;
    cin>>l>>r;
    // cout<<"l,r is "<<l<<","<<r<<endl;
    //[l,r]にある'/'を見ていく
    int ind=lower_bound(slash.begin(),slash.end(),l)-slash.begin();
    while(ind<(int)slash.size()&&slash[ind]<=r){
      // cout<<"slash[ind] is "<<slash[ind]<<endl;
      int one=rsw_one[slash[ind]]-rsw_one[l-1];
      int two=rsw_two[slash[ind]]-rsw_two[r+1];
      // cout<<"one is "<<one<<endl;
      // cout<<"two is "<<two<<endl;
      ans=max(ans,2*min(one,two)+1);
      ind++;
    }
    cout<<ans<<endl;
  }
  return 0;
}