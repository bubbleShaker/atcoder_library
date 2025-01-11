#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  map<int,int> mp;
  set<int> st;
  for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]++,st.insert(a[i]);
  int ans=0;
  for(int i=0;i<n;i++){
    if(mp[a[i]]<=0){//使える餅がないならcontinue
      continue;
    }
    auto itr=st.lower_bound(2*a[i]);
    if(itr!=st.end()&&mp[*itr]>0){//下の餅が0より多いなら使う
      ans++;
      // cout<<"a is "<<a[i]<<", b is "<<*itr<<endl;
      // cout<<"mp["<<*itr<<"] is "<<mp[*itr]<<endl;
      mp[*itr]--;//使ったので減らす
      mp[a[i]]--;
      if(mp[*itr]<=0)st.erase(*itr);
      if(a[i]<=0)st.erase(a[i]);
    }else{//使えないなら使えるまでitr++
      while(itr!=st.end()&&mp[*itr]<=0){
        itr++;
      }
      if(itr!=st.end()){//最後まで見つからなかったなら何もしない?
        ans++;
        mp[*itr]--;
        mp[a[i]]--;
        if(mp[*itr]<=0)st.erase(*itr);
        if(a[i]<=0)st.erase(a[i]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}