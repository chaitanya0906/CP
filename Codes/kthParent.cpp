#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);                      \
	cin.exceptions(cin.failbit);
#define int long long int //Comment when Unnecessary
#define ll long long
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define pii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define endl "\n" // Remove on Interactive

const int N = 300009;
const int mod = 1000000007;

vector<int> twop;
int n, l, a, b;
vector<vector<int>> adj;
vector<vector<int>> up;

// Binary Lifting
void dfs(int v, int p)
{
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
}

void preprocess(int root)
{
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dfs(root, root);
}

int kthParent(int v, int plac)
{
	if (plac == 0)
	{
		return v;
	}
	auto it = upper_bound(all(twop), plac);
	int x = it - twop.begin();
	x--;
	v = up[v][x];
	plac = plac - twop[x];
	return kthParent(v, plac);
}

void pre()
{
	twop.push_back(1);
	for (int i = 0; i < 60; i++)
	{
		twop.push_back(twop.back() * 2);
	}
}

int32_t main()
{
	IOS;
	pre();
	cin >> n;
	adj.resize(n);
	up = adj;
	rep(i, 0, n - 1)
	{
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	preprocess(0);
	cout << kthParent(n - 1, 7) << endl;
	return 0;
}
