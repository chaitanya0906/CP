#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define int long long int
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()

const int N = 500009;
const int mod = 1000000007;

// Template : Number of Elements less than  equal to x in range l to r

vector<int> bit;

struct Query
{
	int l, r, x, idx;
};

struct ArrayElement
{
	int val, idx;
};

bool cmp1(Query q1, Query q2)
{
	return q1.x < q2.x;
}

bool cmp2(ArrayElement x, ArrayElement y)
{
	return x.val < y.val;
}

void update(vector<int> &bit, int idx, int val, int n)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}

int query(vector<int> &bit, int idx, int n)
{
	int sum = 0;
	for (; idx > 0; idx -= idx & -idx)
		sum += bit[idx];
	return sum;
}

void answerQueries(vector<int> &ans, vector<Query> &queries, vector<ArrayElement> &arr)
{
	int n = sz(arr);
	int q = sz(queries);
	bit.assign(n + 1, 0);
	sort(all(arr), cmp2);
	sort(all(queries), cmp1);
	int curr = 0;
	ans.resize(q);
	for (int i = 0; i < q; i++)
	{
		while (arr[curr].val <= queries[i].x && curr < n)
		{
			update(bit, arr[curr].idx + 1, 1, n);
			curr++;
		}
		ans[queries[i].idx] = query(bit, queries[i].r + 1, n) - query(bit, queries[i].l, n);
	}
}

int n, Q;
vector<Query> q;
vector<ArrayElement> a;

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	cin >> n >> Q;
	a.resize(n);
	q.resize(Q);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].val;
		a[i].idx = i;
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> q[i].l >> q[i].r >> q[i].x;
		q[i].idx = i;
	}
	vector<int> ans;
	answerQueries(ans, q, a);
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
}