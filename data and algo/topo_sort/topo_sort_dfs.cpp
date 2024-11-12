#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int to;
};
using Graph=vector<vector<Edge>>;
//参照:https://algo-logic.info/topological-sort/

/* topo_sort(G):グラフGをトポロジカルソート
    返り値:トポロジカルソートされた頂点番号
    計算量:O(|E|+|V|)
*/
void dfs(const Graph &G,int v,vector<bool> &used,vector<int> &ans){
  used[v]=true;
  for(auto e:G[v]){
    if(!used[e.to]){
      dfs(G,e.to,used,ans);
    }
  }
  ans.push_back(v);//帰りがけにpush_back
}
vector<int> topo_sort(const Graph &G){ //bfs
  vector<int> ans;
  int n=(int)G.size();
  vector<bool> used(n,false);
  for(int v=0;v<n;v++){ //未探索の頂点ごとにDFS
    if(!used[v]) dfs(G,v,used,ans);
  }
  reverse(ans.begin(),ans.end()); //逆向きなのでひっくり返す
  return ans;
}