#include <bits/stdc++.h>
using namespace std;

using P=pair<int,int>;

int H,W;
vector<vector<char>> maze;
vector<vector<bool>> seen;
P s,g;

//dfs
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(P p){
  seen[p.first][p.second]=true;
  for(int i=0;i<4;i++){
    int ny=p.first+dy[i];
    int nx=p.second+dx[i];
    if(ny<0||H<=ny||nx<0||W<=nx) continue;
    if(maze[ny][nx]=='#') continue;
    if(seen[ny][nx]) continue;
    dfs(make_pair(ny,nx));
  }
}

int main(){
  cin>>H>>W;
  maze.assign(H,vector<char>(W,'.'));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>maze[i][j];
      if(maze[i][j]=='s'){
        s=make_pair(i,j);
      }else if(maze[i][j]=='g'){
        g=make_pair(i,j);
      }
    }
  }
  
  seen.assign(H,vector<bool>(W,false));
  dfs(s);
  
  if(seen[g.first][g.second]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}