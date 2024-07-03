#include <iostream>
#include <iomanip>
int main(){
  double limit_minute;
  std::cout<<"制限時間を分単位で入力してね"<<'\n';
  std::cin>>limit_minute;
  double prob_cnt;
  std::cout<<"解きたい問題数を入力してね"<<'\n';
  std::cin>>prob_cnt;
  
  std::cout<<std::fixed<<std::setprecision(1);
  
  double ret_minute=limit_minute/prob_cnt;
  std::cout<<"1問に費やす時間"<<'\n';
  std::cout<<ret_minute<<"分"<<'\n';
  return 0;
}

//用途
//制限時間と解きたい問題数から、一問辺りに使う時間を算出する

//エイリアス
//コンパイル…gt3
//実行…t3