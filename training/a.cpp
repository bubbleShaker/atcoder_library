#include <bits/stdc++.h>
using namespace std;
struct Edge{
  int to;
};
using Graph=vector<vector<Edge>>;

vector<int> cc;
void dfs(const Graph &G,int v,int id){
  cc[v]=id;
  for(auto &e:G[v]){
    if(!cc[e.to]==-1){
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
  cc.assign(n,-1);
  int id=0;
  for(int i=0;i<n;i++){
    if(cc[i]==-1){
      dfs(G,i,id);
      id++;
    }
  }
  int q;
  cin>>q;
  while(q--){
    int s,t;
    cin>>s>>t;
    if(cc[s]==cc[t]){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}