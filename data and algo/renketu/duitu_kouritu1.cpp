#include <bits/stdc++.h>
using namespace std;
struct Edge{
  int to;
};
using Graph=vector<vector<Edge>>;
//参考:https://algo-logic.info/is-same-connected-components/

//深さ優先探索
vector<int> cc; //どの連結成分か記録
void dfs(const Graph &G,int v,int id){
  cc[v]=id;
  for(auto e:G[v]){
    if(cc[e.to]==-1){ //訪問済みでなければ探索
      dfs(G,e.to,id);
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  
  Graph G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back({b});
    G[b].push_back({a});
  }
  
  int q;
  cin>>q;
  vector<int> s(q),t(q);
  for(int i=0;i<q;i++){
    cin>>s.at(i)>>t.at(i);
  }
  
  cc.assign(n,-1); //初期化
  int id=0;
  for(int i=0;i<n;i++){
    if(cc[i]==-1){
      dfs(G,i,id);
      id++;
    }
  }
  //idは連結成分の個数にもなっている
  
  for(int i=0;i<q;i++){
    if(cc[s[i]]==cc[t[i]]){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}