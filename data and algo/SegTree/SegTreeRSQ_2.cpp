#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
  int dat[300000],siz=1;
  
  //要素datの初期化を行う(最初は全部ゼロ)
  void init(int N){
    siz=1;
    while(siz<N) siz*=2;
    for(int i=1;i<siz*2;i++) dat[i]=0;
  }
  
  //クエリ1に対する処理
  void update(int pos,int x){
    pos=pos+siz-1;
    dat[pos]=x;
    while(pos>=2){
      pos/=2;
      dat[pos]=dat[pos*2]+dat[pos*2+1]; //8.8節から変更した部分
    }
  }
  
  //クエリ2に対する処理
  int query(int l,int r,int a,int b,int u){
    if(r<=a||b<=l) return 0; //8.8節から変更した部分
    if(l<=a&&b<=r) return dat[u];
    int m=(a+b)/2;
    int AnswerL=query(l,r,a,m,u*2);
    int AnswerR=query(l,r,m,b,u*2+1);
    return AnswerL+AnswerR; //8.8節から変更した部分
  }
};

int N,Q;
int Query[100009],pos[100009],x[100009],l[100009],r[100009];
SegmentTree Z;

int main(){
  //入力
  cin>>N>>Q;
  for(int i=1;i<=Q;i++){
    cin>>Query[i];
    if(Query[i]==1) cin>>pos[i]>>x[i];
    if(Query[i]==2) cin>>l[i]>>r[i];
  }
  
  //クエリ処理
  Z.init(N);
  for(int i=1;i<=Q;i++){
    if(Query[i]==1){
      Z.update(pos[i],x[i]);
    }
    if(Query[i]==2){
      //最初のセルに対応する半開区間は[1,siz+1)
      int Answer=Z.query(l[i],r[i],1,Z.siz+1,1);
      cout<<Answer<<endl;
    }
  }
  return 0;
}