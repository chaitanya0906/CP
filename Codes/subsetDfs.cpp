/*
	Ref : Sanket
        https://codeforces.com/contest/1208/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define int long long
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()

const int N = 2000009;
const int mod = 1000000007;

int n;
vector<int> a;
vector<int> cnt;

void dfs(int x, int bit)
{
	if (x >> bit == 0)
	{
		cnt[x]++;
		// cout << x << " : " << cnt[x] << " | ";
		return;
	}
	if (cnt[x] >= 2)
	{
		// cout << x << " : " << cnt[x] << " | ";
		return;
	}
	dfs(x, bit + 1);
	if (x & (1 << bit))
	{
		x ^= 1 << bit;
		dfs(x, bit + 1);
	}
	// cout << x << " : " << cnt[x] << " | ";
}

void pre()
{
	cnt.assign(N, 0);
}

int32_t main()
{
	IOS;
	pre();
	cin >> n;
	a.resize(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// ans = *max_element(all(a));
	for (int i = (n - 1); i >= 0; i--)
	{
		int cur = a[i];
		int off = 0;
		for (int j = 20; j >= 0; j--)
		{
			if ((a[i] & (1 << j)) == 0)
			{
				if (cnt[off | (1 << j)] >= 2)
				{
					cur = (cur | (1 << j));
					off = (off | (1 << j));
				}
			}
		}
		dfs(a[i], 0);
		if (i >= (n - 2))
			cur = 0;
		ans = max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
