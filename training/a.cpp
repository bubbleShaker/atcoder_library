#include <bits/stdc++.h>
using namespace std;
int main(){
  const long long INF=1e9;
  const long long INFLL=1e18;
  long long n;
  cin>>n;
  vector<long long> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<vector<long long>> g(n+1);
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i][j]=='Y'){
        g[i+1].push_back(j+1);
      }
    }
  }
  vector<long long> cur(n+1,INFLL);//暫定距離を記録
  vector<long long> confirmed(n+1,INFLL);//最短距離が確定した頂点
  auto calcCost=[&](long long dist,long long sum){
    return dist*INF-sum;
  };
  auto dijkstra=[&](long long start){
    priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<tuple<long long,long long,long long>>> hque;
    hque.push({calcCost(0,a[start]),0,start});
    cur[start]=calcCost(0,a[start]);
    while(!hque.empty()){
      auto [_,dist,u]=hque.top();
      hque.pop();
      if(confirmed[u]!=INFLL){// !確定済み頂点である間、キューの最小値を削除し続ける
        continue;// !これを入れないとO(M^2)になってしまうケースがありそう。
        // !実際に実験すると、下の*での確認だけでは、同じ頂点に対して複数の{コスト,頂点}の要素が入りうると分かる。
        // !これを入れないと同じ頂点に対してN回ループ処理することになり、ボトルネックになりうる。
        // !実験メモ
        // !完全グラフに対して、キューへのpushの時にコストが全部同じになるようにしてシミュレーション。
        // !キューの要素は合計で2M個になった。
        // !これらの要素全てについてN回調べると、2M+(2M-N)N回の計算をするため、O(NM)となる。
        // !この!での確認を行えば2M+log(MlogM)でconfirmを全て確定できる。
        // !よって全体でO(MlogM)になりそう。
      }
      long long val=calcCost(dist,cur[u]);
      confirmed[u]=dist;
      cerr<<val<<" "<<dist<<'\n';
      for(auto v:g[u]){
        if(confirmed[v]==INFLL){//隣接している未確定頂点についてcurを更新
          // *正直こっちの確認は計算量削減にはあまり寄与しない
          //各頂点の次数の総和は2Mなので、2M回しかキューには入らなく、!で示した部分があればそれぞれO(1)しか影響しない。
          hque.push({calcCost(dist+1,val+a[v]),dist+1,v});//ヒープキューに暫定距離を入れつつ
          cur[v]=min(cur[v],calcCost(dist+1,val+a[v]));//!暫定距離を更新していく
          //!暫定距離の更新は現在の値とのchminを取りつつ更新することに注意
          //!push時にcur更新、pop時にconfirm確定、という気持ちでよさそう
          //!curは更新されるとは限らないことに注意
        }
      }
    }
  };
  long long q;
  cin>>q;
  for(long long i=0;i<q;i++){
    cur.resize(n+1,(long long)1e18);
    confirmed.resize(n+1,INFLL);
    long long u,v;
    cin>>u>>v;
    dijkstra(u);
    if(confirmed[v]==INFLL){
      cout<<"Impossible"<<'\n';
    }else{
      cout<<confirmed[v]<<" "<<calcCost(confirmed[v],cur[v])<<'\n';
    }
  }
  return 0;
}