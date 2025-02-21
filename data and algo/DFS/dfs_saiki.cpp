#include <bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;
//参考サイト:https://algo-logic.info/dfs/

//深さ優先探索
vector<bool> seen; //既に見たことがある頂点か記録
void dfs(const Graph &G,int v){
  seen[v]=true;
  for(auto next:G[v]){
    if(!seen[next]){ //訪問済みでなければ探索
      dfs(G,next);
    }
  }
}

int main(){
  int V,E;
  cin>>V>>E;
  int s,t;
  cin>>s>>t;
  
  Graph G(V);
  for(int i=0;i<E;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back({b});
    // G[b].push_back({a});
  }
  
  seen.assign(V,false); //初期化
  dfs(G,s);
  if(seen[t]){
    cout<<"yes"<<endl;
  }else{
    cout<<"no"<<endl;
  }
  return 0;
}