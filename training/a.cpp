#include <bits/stdc++.h>
using namespace std;
struct Edge{
  int to;
};
using Graph=vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G){
  vector<int> ans;
  int n=(int)G.size();
  vector<int> ind(n);
  for(int i=0;i<n;i++){
    for(auto e:G[i]){
      ind[e.to]++;
    }
  }
  queue<int> que;
  for(int i=0;i<n;i++){
    if(ind[i]==0){
      que.push(i);
    }
  }
  while(!que.empty()){
    int now=que.front();
    ans.push_back(now);
    que.pop();
    for(auto e:G[now]){
      ind[e.to]--;
      if(ind[e.to]==0){
        que.push(e.to);
      }
    }
  }
  return ans;
}