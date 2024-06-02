template<typename T>
class Doubling{
private:
  vector<T> a;
  vector<vector<T>> dp;
  void init(){
    int n=a.size();
    //今回は日数の最大値が10^9なので、2^29程度まで計算すればよい
    //日数の最大値が10^18とかなら、2^59程度まで計算することになりそう…?
    dp.resize(30,vector<T>(n+1));
    //初期値の代入
    //穴iにいた2^0日後の場所:dp[0][i]
    //穴iにいた2^1日後の場所:dp[1][i]
    //穴iにいた2^2日後の場所:dp[2][i]
    //穴iにいた2^3日後の場所:dp[3][i]
    for(int i=1;i<=n;i++){
      dp[0][i]=a[i-1];
    }
    //前計算
    //1日後の1日後は2日後
    //dp[1][i]=dp[0][dp[0][i]]
    //2日後の2日後は4日後
    //dp[2][i]=dp[1][dp[1][i]]
    //4日後の4日後は8日後
    //dp[3][i]=dp[2][dp[2][i]]
    for(int i=1;i<=29;i++){
      for(int j=1;j<=n;j++){
        dp[i][j]=dp[i-1][dp[i-1][j]];
      }
    }
  }
public:
  Doubling(vector<T> v):a(v){
    init();
  }
  //場所xにいる時、y日後にいる場所を求める
  T calcPos(T x,T y){
    T curPos=x;
    //例:穴2にいた13日後の場所
    //13=2^3+2^2+2^0
    //穴2にいた8日後の場所はdp[3][2]=3
    //穴3にいた4日後の場所はdp[2][3]=7
    //穴7にいた1日後の場所はdp[0][7]=3
    for(int d=29;d>=0;d--){
      if(y&(1<<d)){
        curPos=dp[d][curPos];
      }
    }
    return curPos;
  }
};