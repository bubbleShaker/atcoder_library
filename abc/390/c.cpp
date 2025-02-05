#include <bits/stdc++.h>
using namespace std;
int h,w;
vector<string> s;

bool jo1(int i,int j){//左右
  if(j!=0&&j!=w-1){
    if(s[i][j-1]=='#'&&s[i][j+1]=='#'){
      return true;
    }
  }
  return false;
}

bool jo2(int i,int j){//上下
  if(i!=0&&i!=h-1){
    if(s[i-1][j]=='#'&&s[i+1][j]=='#'){
      return true;
    }
  }
  return false;
}

bool jo3(int i,int j){//左下
  if(i!=h-1&&j!=0){
    if(s[i][j-1]=='#'&&s[i+1][j]=='#'){
      return true;
    }
  }
  return false;
}

bool jo4(int i,int j){//右下
  if(i!=h-1&&j!=w-1){
    if(s[i][j+1]=='#'&&s[i+1][j]=='#'){
      return true;
    }
  }
  return false;
}

bool jo5(int i,int j){//左上
  if(i!=0&&j!=0){
    if(s[i][j-1]=='#'&&s[i-1][j]=='#'){
      return true;
    }
  }
  return false;
}

bool jo6(int i,int j){//右上
  if(i!=0&&j!=w-1){
    if(s[i][j+1]=='#'&&s[i-1][j]=='#'){
      return true;
    }
  }
  return false;
}


int main(){
  cin>>h>>w;
  s.resize(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='?'){
        if(jo1(i,j)||jo2(i,j)||jo3(i,j)||jo4(i,j)||jo5(i,j)||jo6(i,j)){
          s[i][j]='#';
        }else{
          s[i][j]='.';
        }
      }
    }
  }
  
  int si,sj;
  bool end=false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        si=i;
        sj=j;
        end=true;
        break;
      }
    }
    if(end){
      break;
    }
  }
  
  int size_h=0;
  for(int i=si;i<h;i++){
    if(s[i][sj]=='#'){
      size_h++;
    }else{
      break;
    }
  }
  
  int size_w=0;
  for(int j=sj;j<w;j++){
    if(s[si][j]=='#'){
      size_w++;
    }else{
      break;
    }
  }
  
  string ws;
  for(int j=0;j<w;j++){
    ws+='.';
  }
  vector<string> ss(h);
  for(int i=0;i<h;i++){
    ss[i]=ws;
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(si<=i&&i<si+size_h&&sj<=j&&j<sj+size_w){
        ss[i][j]='#';
      }
    }
  }
  
  // for(int i=0;i<h;i++){
  //   cout<<s[i]<<endl;
  // }
  
  // cout<<endl;
  
  // for(int i=0;i<h;i++){
  //   cout<<ss[i]<<endl;
  // }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]!=ss[i][j]){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}