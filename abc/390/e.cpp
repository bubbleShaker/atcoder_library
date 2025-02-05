#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=2e9;
  int n,x;
  cin>>n>>x;
  vector<int> v(n),a(n),c(n);
  for(int i=0;i<n;i++){
    cin>>v[i]>>a[i]>>c[i];
  }
  vector<int> dp1(5010,-INF);//dp1[i][j]:i番目まで見た時カロリーjでのビタミン1の最大値
  vector<int> dp2(5010,-INF);
  vector<int> dp3(5010,-INF);
  dp1[0]=0;
  dp2[0]=0;
  dp3[0]=0;
  for(int i=0;i<n;i++){
    for(int j=x;j>=0;j--){
      if(v[i]==1){
        if(j-c[i]>=0&&dp1[j-c[i]]!=-INF){
          dp1[j]=max(dp1[j-c[i]]+a[i],dp1[j]);
        }
      }
      if(v[i]==2){
        if(j-c[i]>=0&&dp2[j-c[i]]!=-INF){
          dp2[j]=max(dp2[j-c[i]]+a[i],dp2[j]);
        }
      }
      if(v[i]==3){
        if(j-c[i]>=0&&dp3[j-c[i]]!=-INF){
          dp3[j]=max(dp3[j-c[i]]+a[i],dp3[j]);
        }
      }
    }
  }
  int v1=0,v2=0,v3=0;
  int ans=0;
  for(int i=0;i<=x;i++){
    if(dp1[i]!=-INF&&dp2[i]!=-INF&&dp3[i]!=-INF){
      ans=max(ans,min({dp1[i],dp2[i],dp3[i]}));
    }
  }
  cout<<ans<<endl;
  return 0;
}