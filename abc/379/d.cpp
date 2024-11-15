#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int Q;
  cin>>Q;
  list<pair<ll,ll>> days_height;
  bool is_new=true;
  while(Q--){
    int Query;
    cin>>Query;
    if(Query==1){
      if(is_new){
        days_height.push_back(make_pair(1,0));
        is_new=false;
      }else{
        auto itr=days_height.end();
        itr--;
        itr->first++;
        // days_height[days_height.size()-1].first++;
      }
    }
    if(Query==2){
      ll T;
      cin>>T;
      auto itr=days_height.begin();
      for(itr;itr!=days_height.end();itr++){
        itr->second+=T;
      }
      is_new=true;
    }
    if(Query==3){
      ll H;
      cin>>H;
      int cnt=0;
      int ret=0;
      auto itr=days_height.begin();
      for(itr;itr!=days_height.end();itr++){
        if(itr->second>=H){
          cnt++;
          ret+=itr->first;
        }
      }
      while(cnt--){
        days_height.pop_front();
      }
      if(days_height.size()==0){
        is_new=true;
      }
      cout<<ret<<endl;
    }
  }
  return 0;
}