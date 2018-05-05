#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  int n, result = 1;
  cin >> n;
  int d[n];
  list_input(d, n)
  sort(d, d+n, greater<int>());
  rep(i, n-1){
    if (d[i] > d[i+1]) {
      result += 1;
    }
  }
  cout << result << '\n';
}
