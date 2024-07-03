#include <iostream>
#include <iomanip>
int main(){
  double remain_tee;
  std::cout<<"目標までのTEEを万単位で入力してね"<<'\n';
  std::cin>>remain_tee;
  double complete_day;
  std::cout<<"目標を達成したい日数を入力してね"<<'\n';
  std::cin>>complete_day;
  
  std::cout<<"TEE1万上げるペース"<<'\n';
  double ret_day=complete_day/remain_tee;
  
  std::cout<<std::fixed<<std::setprecision(1);
  
  std::cout<<ret_day<<"日"<<'\n';
  double day_tee=10000.0/ret_day;
  std::cout<<"1日に上げるTEE"<<'\n';
  std::cout<<day_tee<<'\n';
  
  const double gray_tee=25;
  double gray_cnt=day_tee/gray_tee;
  std::cout<<"1日に解く灰diff問題の数"<<'\n';
  std::cout<<gray_cnt<<'\n';
  
  const double brown_tee=50;
  double brown_cnt=day_tee/brown_tee;
  std::cout<<"1日に解く茶diff問題の数"<<'\n';
  std::cout<<brown_cnt<<'\n';
  
  const double green_tee=130;
  double green_cnt=day_tee/green_tee;
  std::cout<<"1日に解く緑diff問題の数"<<'\n';
  std::cout<<green_cnt<<'\n';
  
  return 0;
}

//用途
//目標までのTEEと達成したい日数から、TEEを1万上げるペース、1日に上げるTEEなどを算出する
//灰,茶の1問辺りのTEEは平均値を適当に計算した

//エイリアス
//コンパイル…gt2
//実行…t2