#include <iostream>
#include <vector>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::string s;
  std::cin>>s;
  const int CHAR_MAX=3;
  const int SET_MAX=1<<4; //2^4 
  std::cout<<SET_MAX<<'\n';
  return 0;
}