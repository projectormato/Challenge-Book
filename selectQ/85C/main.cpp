#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  ll n, y, now = 0, rex = -1, rey = -1, rez = -1;
  cin >> n >> y;
  rep(i, n+1){
    rep(j, n+1){
      int k = n-i-j;
      if (0 > k) continue;
      now = 10000*i + 5000*j + 1000*k;
      if (now == y) {
        rex = i;
        rey = j;
        rez = k;
        break;
      }
    }
  }
  cout << rex << " " << rey << " " << rez<< '\n';
}
