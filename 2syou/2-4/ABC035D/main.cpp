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

int N, M, x, y, result = 0;
int par[100010], rnk[100010]; //Union-findの親と偏りなくすやつ

void init(int n){
  rep(i, N){
    par[i] = i;
    rnk[i] = 0;
  }
}

// 木のrootを求める
int find(int x){
  if (par[x] == x) {
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

//結合する
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if (x == y) return; //元々同じなら
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  }else{
    par[y] = x;
    if (rnk[x] == rnk[y]) {
      rnk[x] += 1;
    }
  }
}

int main(){
  cin >> N >> M;
  init(N);
  rep(i, M){
    cin >> x >> y;
    unite(x-1, y-1); //配列の0から始まるやつの関係
  }

  rep(i, N){
    if (par[i] == i) {
      result += 1;
    }
  }
  cout << result-1 << endl;
}
