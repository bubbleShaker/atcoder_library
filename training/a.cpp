#include <bits/stdc++.h>
using namespace std;
struct Edge{
  long long to;
  long long cost;
};
using Graph=vector<vector<Edge>>;
using P=pair<int,int>;
const long long INF=1LL<<60;

void dijkstra(const Graph &G,int s,vector<long long> &dis,vector<int> &prev){
  int N=G.size();
  dis.resize(N,INF);
  prev.resize(N,-1);
  dis[s]=0;
  priority_queue<P,vector<P>,greater<P>> pq;
  pq.emplace(dis[s],0);
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
        prev[e.to]=v;
        pq.emplace(dis[e.to],e.to);
      }
    }
  }
}

vector<int> get_path(const vector<int> &prev,int t){
  vector<int> path;
  for(int cur=t;cur!=-1;cur=prev[cur]){
    path.push_back(cur);
  }
  reverse(path.begin(),path.end());
  return path;
}