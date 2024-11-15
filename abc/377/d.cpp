#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  set<int> set_l,set_r;
  map<int,int> map_r;
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    set_l.insert(l);
    set_r.insert(r);
    map_r[r]=l;
  }
  set_r.insert(m+1);
  int l=0,r=1;
  long long ans=0;
  bool moved=true;
  while(l!=m){
    l++;
    if(moved){
      while(!set_r.count(r)){
        r++;
        if(map_r[r]<l){
          r++;
        }
      }
    }
    int add=r-l;
    // cout<<"l is "<<l<<",r is "<<r<<", add is "<<add<<endl;
    ans+=r-l;
    if(set_l.count(l)){
      if(map_r[r]<=l&&r<m+1){
        r++;
        moved=true;
      }
    }else{
      moved=false;
    }
  }
  cout<<ans<<endl;
  return 0;
}