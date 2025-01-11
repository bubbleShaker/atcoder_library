#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  ll s;
  cin>>n>>s;
  vector<ll> a(n),ra(n);
  for(int i=0;i<n;i++) cin>>a[i],ra[n-1-i]=a[i];
  vector<ll> rsw(n+1),r_rsw(n+1);
  for(int i=1;i<=n;i++){
    rsw[i]=rsw[i-1]+a[i-1];
    r_rsw[i]=r_rsw[i-1]+ra[i-1];
  }
  s%=rsw[n];
  for(int i=0;i<=n;i++){
    ll rem=s-rsw[i];
    if(rem<0)break;
    auto itr=lower_bound(r_rsw.begin(),r_rsw.end(),rem);
    if(itr!=r_rsw.end()&&*itr==rem){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}