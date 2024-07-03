#include <iostream>
#include <iomanip>
int main(){
  
  double day;
  std::cout<<"1万TEE上がる日数を入力してね"<<'\n';
  std::cin>>day;
  double remain_tee;
  std::cout<<"目標までのTEEを万単位で入力してね"<<'\n';
  std::cin>>remain_tee;
  double age;
  std::cout<<"あなたの現在の年齢を入力してね"<<'\n';
  std::cin>>age;
  
  std::cout<<std::fixed<<std::setprecision(1);
  
  double ret_day=day*remain_tee;
  std::cout<<"目標達成までの日数:\n"<<(int)ret_day<<"日"<<'\n';
  
  double ret_year=ret_day/365.0;
  std::cout<<"目標達成までの年数:\n"<<ret_year<<"年"<<'\n';
  
  double ret_age=ret_year+age;
  std::cout<<"目標達成時の年齢:\n"<<ret_age<<"歳"<<'\n';
  
  double day_tee=10000.0/day;
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

//自分の勉強ペースメモ
//*夏休みや就活などのイベントがない暇な時期…40日で1万TEE
//*学校での課題提出・レポート作成など少しやることがある時…70日で1万TEE
//*葬式や就活・テスト勉強やゼミ準備など、比較的忙しい時期…150日で1万TEE

//用途
//TEE1万上昇にかかる日数から、目標TEEまでにかかる日数などを算出する
//TEEがレートに強い相関があると認識しているため、信頼性の高いデータになると思う
//例:青下位の人は適当にサンプルを取ってくると30万TEEくらいが平均

//エイリアス
//コンパイル…gt1
//実行…t1