#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  std::vector<int> one_idx;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    if(a[i]==1){
      one_idx.push_back(i); //1のidxを保持
    }
  }
  std::vector<int> plus_dist(n),minus_dist(n);
  //右向き
  for(int i=0;i<n;i++){
    auto itr=std::lower_bound(one_idx.begin(),one_idx.end(),i);
    if(itr==one_idx.end()){ //右に1が存在しない場合
      plus_dist[i]=std::min(a[i]-1,n-1-i); //末尾の文字までの距離と自分-1の小さい方
    }else if(a[i]==1){ //自分自身が1だった場合
      plus_dist[i]=0; //距離0
    }else{ //右に1が存在して自分自身が1でない時
      plus_dist[i]=std::min(a[i]-1,(*itr)-i); //その要素までの距離
    }
  }
  //左向き 左に見て一番近い1or先頭までの距離の小さい方を記録
  for(int i=0;i<n;i++){
    auto itr=std::lower_bound(one_idx.begin(),one_idx.end(),i); 
    if(itr==one_idx.begin()&&itr==one_idx.end()){ //1が存在していない場合
      minus_dist[i]=std::min(a[i]-1,i);
    }else if(itr==one_idx.end()){ //右に1が存在せず左に1が存在する場合
      itr--;
      minus_dist[i]=std::min(a[i]-1,i-(*itr)); 
    }else if(a[i]==1){ //自分自身が1である時
      minus_dist[i]=0;
    }else if(itr==one_idx.begin()){ //右に1が存在するが最初の要素である時
      minus_dist[i]=std::min(a[i]-1,i);
    }else{ //左に1が存在する時
      itr--;
      minus_dist[i]=std::min(a[i]-1,i-(*itr));
    }
  }
  for(int i=0;i<n;i++){
    std::cout<<minus_dist[i]<<((i!=n-1)?' ':'\n');
  }
  for(int i=0;i<n;i++){
    std::cout<<plus_dist[i]<<((i!=n-1)?' ':'\n');
  }
  int k_1_max=0;
  for(int i=0;i<n;i++){
    k_1_max=std::max(k_1_max,std::min(plus_dist[i],minus_dist[i])); //小さいほうの最大値を調べる
  }
  std::cout<<k_1_max+1<<'\n'; //k-1の最大値を調べたので+1
  return 0;
}