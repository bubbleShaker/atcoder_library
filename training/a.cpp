#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  for(int i=0;i<n-2;i++){
    if(s[i]=='#'&&s[i+1]=='.'&&s[i+2]=='#'){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}