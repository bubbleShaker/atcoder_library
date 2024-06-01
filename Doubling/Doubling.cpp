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
    for(int i=1;i<=n;i++){
      dp[0][i]=a[i-1];
    }
    //前計算
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
    for(int d=29;d>=0;d--){
      if(y&(1<<d)){
        curPos=dp[d][curPos];
      }
    }
    return curPos;
  }
};