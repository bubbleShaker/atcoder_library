#include <bits/stdc++.h>
using namespace std;
//参考:https://algo-logic.info/bellman-ford/
//テスト用:https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja

struct Edge{
  long long from;
  long long to;
  long long cost;
};
using Edges=vector<Edge>;
const long long INF=1LL<<60;

/* bellman_ford(Es,V,s,dis)
    入力:全ての辺Es,頂点数V,開始点s,最短経路を記録するdis
    出力:負の閉路が存在するならtrue
    計算量:O(|E||V|)
    副作用:disが書き換えられる
*/

bool bellman_ford(const Edges &Es,int V,int s,vector<long long> &dis){
  dis.resize(V,INF);
  dis[s]=0;
  int cnt=0;
  while(cnt<V){
    bool end=true;
    for(auto e:Es){
      if(dis[e.from]!=INF&&dis[e.from]+e.cost<dis[e.to]){
        dis[e.to]=dis[e.from]+e.cost;
        end=false;
      }
    }
    if(end) break;
    cnt++;
  }
  return (cnt==V);
}

int main(){
  int V,E;
  cin>>V>>E;
  int r;
  cin>>r;
  Edges Eds(E);
  for(int i=0;i<E;i++){
    long long s,t,d;
    cin>>s>>t>>d;
    Eds[i]={s,t,d};
  }
  vector<long long> dis;
  if(bellman_ford(Eds,V,r,dis)){
    cout<<"NEGATIVE CYCLE"<<endl;
  }else{
    for(int v=0;v<V;v++){
      if(dis[v]==INF){
        cout<<"INF"<<endl;
      }else{
        cout<<dis[v]<<endl;
      }
    }
  }
}