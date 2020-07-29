// https://www.hackerrank.com/challenges/kingdom-division/problem
/**
 *  author: chaitanya
 *  created: 12:39:00 PM, 29 July 2020
 **/
#include <bits/stdc++.h>
using namespace std;

#define intll 1
#define interactive 0

#ifdef chaitanya
#include "/home/chaitanya/.templates/header.h"
#else
#define debug(x...)
#endif

#if !interactive
#define IOS                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);                      \
  cin.exceptions(cin.failbit);
#define endl "\n"
#else
#define IOS
#endif

#if intll
#define int long long int
#endif

#define ll long long
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define F first
#define S second

const int N = 300009;
const int mod = 1000000007;
int n;
vvi adj;
int ans[N][4];

void dfs(int x, int p) {
  vvi keep(4);
  trav(it, adj[x]) {
    if (it == p)
      continue;
    dfs(it, x);
    rep(i, 0, 4) keep[i].push_back(ans[it][i]);
  }
  // 0 0
  // Atleast one must be same so -= *keep[2][i];
  if (sz(keep[0]) == 0) {
    ans[x][0] = 0;
  } else {
    ans[x][0] = 1;
    int minus = 1;
    rep(i, 0, sz(keep[0])) {
      ans[x][0] *= ((keep[1][i] + keep[2][i]) % mod);
      ans[x][0] %= mod;
      minus *= (keep[2][i]);
      minus %= mod;
    }
    ans[x][0] += (mod - minus);
    ans[x][0] %= mod;
  }
  // 0 1
  if (sz(keep[0]) == 0) {
    ans[x][1] = 1;
  } else {
    ans[x][1] = 1;
    rep(i, 0, sz(keep[0])) {
      ans[x][1] *= ((keep[1][i] + keep[2][i]) % mod);
      ans[x][1] %= mod;
    }
  }
  // 1 0
  if (sz(keep[0]) == 0) {
    ans[x][2] = 0;
  } else {
    ans[x][2] = 1;
    int minus = 1;
    rep(i, 0, sz(keep[0])) {
      ans[x][2] *= ((keep[0][i] + keep[3][i]) % mod);
      ans[x][2] %= mod;
      minus *= (keep[0][i]);
      minus %= mod;
    }
    ans[x][2] += (mod - minus);
    ans[x][2] %= mod;
  }
  // 1 1
  if (sz(keep[0]) == 0) {
    ans[x][3] = 1;
  } else {
    ans[x][3] = 1;
    rep(i, 0, sz(keep[0])) {
      ans[x][3] *= ((keep[0][i] + keep[3][i]) % mod);
      ans[x][3] %= mod;
    }
  }
  // Exit
  keep.clear();
}

void pre() {}

int32_t main() {
  IOS;
  pre();
  cin >> n;
  adj.resize(n);
  int x, y;
  for (int i = 0; i < (n - 1); i++) {
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, -1);
  cout << (ans[0][0] + ans[0][2]) % mod << endl;
  return 0;
}