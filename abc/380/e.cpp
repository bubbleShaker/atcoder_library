#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int n,q;
  cin>>n>>q;
  dsu uf(n+1);
  while(q--){
    int t;
    cin>>t;
    if(t==1){
      int u,v;
      cin>>u>>v;
      uf.merge(u,v);
    }else{
      int u;
      cin>>u;
      cout<<uf.size(u)<<endl;
    }
  }
  return 0;
}