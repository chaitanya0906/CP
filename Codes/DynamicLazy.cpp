#include <bits/stdc++.h>
using namespace std;

const int N = 500009;
const int mod = 1000000007;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()

#define MAXN 300005
#define LOGN 25

struct node
{
	int l, r;
	int sum;
	bool updateChild;
	node() : l(-1), r(-1), sum(0), updateChild(true) {}
};

struct DynamicSegTree
{

	vector<node> seg;
	DynamicSegTree()
	{
		seg.reserve(2 * MAXN * LOGN); // Size of SegTree
		seg.resize(2);
	}

	void update(int v, int tl, int tr, int l, int r, long long val)
	{
		if (l > r)
			return;
		if (l == tl and r == tr)
		{
			seg[v].sum = (tr - tl + 1) * val;
			seg[v].updateChild = true;
			return;
		}
		int tm = (tl + tr) / 2;
		if (seg[v].updateChild)
		{
			if (seg[v].l == -1)
			{
				seg[v].l = seg.size();
				seg.emplace_back();
			}
			seg[seg[v].l].updateChild = true;
			seg[seg[v].l].sum = (seg[v].sum / (tr - tl + 1)) * (tm - tl + 1);
		}
		if (seg[v].updateChild)
		{
			if (seg[v].r == -1)
			{
				seg[v].r = seg.size();
				seg.emplace_back();
			}
			seg[seg[v].r].updateChild = true;
			seg[seg[v].r].sum = seg[v].sum - seg[seg[v].l].sum;
		}
		seg[v].updateChild = false;
		update(seg[v].l, tl, tm, l, min(tm, r), val);
		update(seg[v].r, tm + 1, tr, max(tm + 1, l), r, val);
		seg[v].sum = seg[seg[v].l].sum + seg[seg[v].r].sum;
	}
};

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	int n, q, l, r, k;
	cin >> n >> q;
	DynamicSegTree T;
	T.update(1, 1, n, 1, n, 1);
	while (q--)
	{
		cin >> l >> r >> k;
		k--;
		T.update(1, 1, n, l, r, k);
		cout << T.seg[1].sum << endl;
	}
	return 0;
}
