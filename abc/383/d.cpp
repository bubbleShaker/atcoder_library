#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
//参考:https://algo-method.com/descriptions/64

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
    const int MAX=20000000;
    vector<bool> isprime = Eratosthenes(MAX);
    ll n;
    cin>>n;
    
    vector<ll> p_vec;
    for(ll i=0;i<=MAX;i++){ //sqrt(n)以下の素数を列挙
      if(isprime[i])p_vec.push_back(i*i);
    }
    ll m=p_vec.size();
    ll ans=0;
    for(ll i=0;i<m;i++){
      ll p_2=p_vec[i];
      auto q_2itr=lower_bound(p_vec.begin(),p_vec.end(),n/p_2);
      if(q_2itr==p_vec.end())continue;
      else if(p_2*(*q_2itr)<=n)ans++;
    }
    cout<<ans<<endl;
}