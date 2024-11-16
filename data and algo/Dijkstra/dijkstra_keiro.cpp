#include <bits/stdc++.h>
using namespace std;
//参考:https://algo-logic.info/dijkstra/
struct Edge{
  long long to;
  long long cost;
};
using Graph=vector<vector<Edge>>;
using P=pair<int,int>;
const long long INF=1LL<<60;

/* dijkstra(G,s,dis,prev)
    入力:グラフG,開始点s,距離を格納するdis,最短経路の前の点を記録するprev
    計算量:O(|E|log|V|)
    副作用:dis,prevが書き換えられる
*/
void dijkstra(const Graph &G,int s,vector<long long> &dis,vector<int> &prev){
  int N=G.size();
  dis.resize(N,INF);
  prev.resize(N,-1); //初期化
  priority_queue<P,vector<P>,greater<P>> pq;
  dis[s]=0;
  pq.emplace(dis[s],s);
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    int v=p.second;
    if(dis[v]<p.first){
      continue;
    }
    for(auto &e:G[v]){
      if(dis[e.to]>dis[v]+e.cost){
        dis[e.to]=dis[v]+e.cost;
        prev[e.to]=v; //頂点vを通ってe.toにたどり着いた
        pq.emplace(dis[e.to],e.to);
      }
    }
  }
}

/* get_path(prev,t)
    入力:dijkstraで得たprev,ゴールt
    出力:tへの最短経路のパス
*/
vector<int> get_path(const vector<int> &prev,int t){
  vector<int> path;
  for(int cur=t;cur!=-1;cur=prev[cur]){
    path.push_back(cur);
  }
  reverse(path.begin(),path.end()); //逆順なのでひっくり返す
  return path;
}