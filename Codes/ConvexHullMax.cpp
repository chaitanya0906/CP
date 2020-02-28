// FAIRNUT RECTANGLES
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

// MAX CONVEX HULL TRICK
bool Q;
struct Line
{
	mutable ll k, m, p;
	bool operator<(const Line &o) const
	{
		return Q ? p < o.p : k < o.k;
	}
};
struct LineContainer : multiset<Line>
{
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b)
	{
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y)
	{
		if (y == end())
		{
			x->p = inf;
			return false;
		}
		if (x->k == y->k)
			x->p = x->m > y->m ? inf : -inf;
		else
			x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m)
	{
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z))
			z = erase(z);
		if (x != begin() && isect(--x, y))
			isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x)
	{
		assert(!empty());
		Q = 1;
		auto l = *lower_bound({0, 0, x});
		Q = 0;
		return l.k * x + l.m;
	}
};

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> v;
	v.resize(n);
	rep(i, 0, n)
	{
		cin >> v[i].F.F >> v[i].F.S >> v[i].S;
	}
	sort(all(v));
	LineContainer temp;
	vector<int> dp(n, 0);
	dp[0] = v[0].F.F * v[0].F.S - v[0].S;
	temp.add(-v[0].F.F, dp[0]);
	rep(i, 1, n) // MAAAAAA BACHAO AISE MISTAKES SE
	{
		dp[i] = temp.query(v[i].F.S) - v[i].S + v[i].F.F * v[i].F.S;
		dp[i] = max(dp[i], (v[i].F.F * v[i].F.S - v[i].S)); // PLEASE
		temp.add(-v[i].F.F, dp[i]);
	}
	cout << (*max_element(all(dp))) << endl;
	return 0;
}
