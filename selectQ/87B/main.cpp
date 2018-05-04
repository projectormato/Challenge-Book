#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  int a, b, c, x, now, result = 0;
  cin >> a >> b >> c >> x;
  rep(i, a+1){
    rep(j, b+1){
      rep(k, c+1){
        now = i*500 + j*100 + k*50;
        if (now == x) result += 1;
      }
    }
  }
  cout << result << '\n';
}
