#include <bits/stdc++.h>
using namespace std;

char hanten(char c){
  if(isupper(c)) return (char)tolower(c);
  else if (islower(c)) return (char)toupper(c);
}

int main(){
  string s;
  cin>>s;
  int q;
  cin>>q;
  long long n=s.size();
  while(q--){
    long long k;
    cin>>k;
    long long a=1;
    bool is_hanten=false;
    while(n<k){
      a=1;
      while(a*n<k) a*=2;
      a/=2;
      is_hanten=!is_hanten;
      k=k-a*n;
    }
    if(is_hanten){
      cout<<hanten(s[k-1])<<" ";
    }else{
      cout<<s[k-1]<<" ";
    }
  }
  cout<<endl;
  return 0;
}