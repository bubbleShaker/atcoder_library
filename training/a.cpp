#include <bits/stdc++.h>
using namespace std;

char flip(char c){
  if('a'<=c&&c<='z'){
    return (c-'a')+'A';
  }
  else{
    return (c-'A')+'a';
  }
}

int main(){
  string s;
  cin>>s;
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    if(i){cout<<" ";}
    long long k;
    cin>>k;
    k--;
    long long blk=k/s.size();
    long long pt=k%s.size();
    if(__builtin_popcountll(blk)%2){
      cout<<flip(s[pt]);
    }
    else{
      cout<<s[pt];
    }
  }cout<<endl;
  return 0;
}