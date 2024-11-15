#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long m;
  cin>>n>>m;
  vector<long long> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<long long> rsw(n+1);
  for(int i=1;i<=n;i++){
    rsw[i]+=rsw[i-1]+a[i];
    rsw[i]%=m;
  }
  long long sum=0;
  for(int i=1;i<=n;i++){
    sum+=rsw[i];
  }
  long long ans=sum;
  for(int i=n;i>=2;i--){
    sum-=(long long)i*a[n+1-i];
    while(sum<0){
      sum+=m;
    }
    ans+=sum;
  }
  cout<<ans<<endl;
  return 0;
}