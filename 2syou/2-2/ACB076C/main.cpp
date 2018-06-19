#include<bits/stdc++.h>
using namespace std;

#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define gets(x) x; cin >> x;
#define puts(x) x; cout << x << endl;
#define list_input(x, n) x[n]; rep(i,n){ gets(x[i]);}
#define ll long long
typedef pair<int, int> P;

int main(){
  string S, T;
  cin >> S >> T;
  int target = 0, start = -1, now = 0;
  rep(i, S.size()){
    while (true) {
      if (target >= T.size()) {
        start = i;
      }
      if (S[now] == T[target] || S[now] == '?') {
        now += 1;
        target += 1;
      }else{
        now = i+1;
        target = 0;
        break;
      }
    }
  }
  if (start != -1) {
    FOR(i, start, start+T.size()){
      S[i] = T[i-start];
    }
  }else{
    cout << "UNRESTORABLE" << endl;
    exit(0);
  }
  rep(i, S.size()){
    if (S[i] == '?') {
      S[i] = 'a';
    }
  }
  cout << S << endl;
}
