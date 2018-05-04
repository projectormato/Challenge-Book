#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  int N, result = 0;
  cin >> N;
  ll a[N];
  list_input(a, N)
  bool is_even_flag = true;
  while (true) {
    rep(i, N){
      if (a[i] % 2 == 1) is_even_flag = false;
    }
    if (!is_even_flag) break;
    result += 1;
    rep(i, N){
      a[i] /= 2;
    }
  }
  cout << result << "\n";
}
