#include <bits/stdc++.h>
using namespace std;
int h,w,d;
vector<int> dx={-1,0,1,0};
vector<int> dy={0,1,0,-1};

void dfs(vector<string> &s,int x,int y,int rem){
  //sについて、(x,y)からdfsをする
  if(rem==0) return;
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<0||nx>=h||ny<0||ny>=w)continue;//マスの外ならcontinue
    if(s[nx][ny]=='#')continue;//壁ならcontinue
    if(s[nx][ny]=='H')continue;//加湿器ならcontinue
    if(s[nx][ny]-'0'>rem-1)continue;//今の場所よりも余裕があるならばcontinue
    s[nx][ny]=(rem-1)+'0';//訪れたらrem-1の文字とする
    // cout<<"nx,ny is"<<nx<<" "<<ny<<endl;
    dfs(s,nx,ny,rem-1);//そこからdfsを行う
  }
}

int main(){
  cin>>h>>w>>d;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='H'){
        // cout<<"i,j is "<<i<<" "<<j<<endl;
        dfs(s,i,j,d);
      }
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='H'||s[i][j]!='.'){
        if(s[i][j]=='#')continue;
        ans++;
      }
    }
  }
  // for(int i=0;i<h;i++){
  //   cout<<s[i]<<endl;
  // }
  cout<<ans<<endl;
  return 0;
}