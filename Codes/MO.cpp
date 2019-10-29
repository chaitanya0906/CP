#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
// #define int long long int
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()

const int N = 500009;
const int mod = 1000000007;

//  MO's Template :- https://cp-algorithms.com/data_structures/sqrt_decomposition.html

long long int ans = 0;
void remove(int idx);       // TODO: remove value at idx from data structure
void add(int idx);	  // TODO: add value at idx from data structure
long long int get_answer(); // TODO: extract the current answer of the data structure

const int block_size = 500;

struct Query
{
	int l, r, idx;
	bool operator<(Query other) const
	{
		return make_pair(l / block_size, r) <
		       make_pair(other.l / block_size, other.r);
	}
};

vector<long long int> mo_s_algorithm(vector<Query> &queries)
{
	vector<long long int> answers(queries.size());
	sort(queries.begin(), queries.end());

	// TODO: initialize data structure

	int cur_l = 0;
	int cur_r = -1;
	// invariant: data structure will always reflect the range [cur_l, cur_r]
	for (Query q : queries)
	{
		while (cur_l > q.l)
		{
			cur_l--;
			add(cur_l);
		}
		while (cur_r < q.r)
		{
			cur_r++;
			add(cur_r);
		}
		while (cur_l < q.l)
		{
			remove(cur_l);
			cur_l++;
		}
		while (cur_r > q.r)
		{
			remove(cur_r);
			cur_r--;
		}
		answers[q.idx] = get_answer();
	}
	return answers;
}

int t, n;
vector<int> a;
vector<int> cnt((1e6) + 9, 0);

void remove(int idx)
{
	ans -= (long long int)((long long int)(a[idx]) * cnt[a[idx]] * cnt[a[idx]]);
	cnt[a[idx]]--;
	ans += (long long int)((long long int)(a[idx]) * cnt[a[idx]] * cnt[a[idx]]);
}

void add(int idx)
{
	ans -= (long long int)((long long int)(a[idx]) * cnt[a[idx]] * cnt[a[idx]]);
	cnt[a[idx]]++;
	ans += (long long int)((long long int)(a[idx]) * cnt[a[idx]] * cnt[a[idx]]);
}

long long int get_answer()
{
	return ans;
}

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	cin >> n >> t;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<Query> q;
	q.resize(t);
	for (int i = 0; i < t; i++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].l--;
		q[i].r--;
		q[i].idx = i;
	}
	vector<long long int> A;
	A.resize(t);
	A = mo_s_algorithm(q);
	for (auto i : A)
		cout << i << endl;
	return 0;
}
