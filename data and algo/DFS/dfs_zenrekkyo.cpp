#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
//参照:https://algo-logic.info/brute-force-dfs/

//深さ優先探索
int dfs(string &S){
  ll ret=0;
  vector<char> lis={'3','5','7'};
  if((int)S.size()>0){ //最初はSは空なので注意
    if(stoll(S)>N){ //Nを超えてたら探索しない
      return ret;
    }else{ //N以下の時3,5,7がそれぞれ1回以上登場するか確かめる
      bool ok=true;
      for(auto c:lis){
        if(S.find(c)==string::npos) ok=false;
      }
      if(ok) ret++;
    }
  }
  for(auto c:lis){ //3つに分岐する
    S.push_back(c);
    ret+=dfs(S);
    S.pop_back();
  }
  return ret;
}

int main(){
  cin>>N;
  string S="";
  cout<<dfs(S)<<endl;
}