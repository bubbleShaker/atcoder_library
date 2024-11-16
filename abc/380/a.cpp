#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  vector<int> cnt(4);
  for(int i=0;i<s.size();i++){
    if(s[i]=='1') cnt[1]++;
    if(s[i]=='2') cnt[2]++;
    if(s[i]=='3') cnt[3]++;
  }
  if(cnt[1]==1&&cnt[2]==2&&cnt[3]==3) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}