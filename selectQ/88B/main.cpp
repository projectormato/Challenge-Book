#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define list_input(x, n) x[n]; rep(i,n){ cin >> x[i];}
#define ll long long

int main(){
  int n, alice = 0, bob = 0;
  cin >> n;
  int a[110];
  list_input(a, n)
  sort(a, a+n, greater<int>());
  step(i, 0, n, 2){
    alice += a[i];
    bob += a[i+1];
  }
  cout << alice - bob << '\n';
}
