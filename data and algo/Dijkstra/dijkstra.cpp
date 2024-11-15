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

/* dijkstra(G,s,dis)
    入力:グラフG,開始点s,距離を格納するdis
    計算量:O(|E|log|V|)
    副作用:disが書き換えられる
*/

void dijkstra(const Graph &G,int s,vector<long long> &dis){
  int N=G.size();
  dis.resize(N,INF);
  priority_queue<P,vector<P>,greater<P>> pq; //「仮の最短距離,頂点」が小さい順に並ぶ
  dis[s]=0;
  pq.emplace(dis[s],s);
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    int v=p.second;
    if(dis[v]<p.first){ //最短距離でなければ無視
      continue;
    }
    for(auto &e:G[v]){
      if(dis[e.to]>dis[v]+e.cost){ //最短距離候補ならpriority_queueに追加
        dis[e.to]=dis[v]+e.cost;
        pq.emplace(dis[e.to],e.to);
      }
    }
  }
}