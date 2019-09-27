#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define all(a) a.begin(), a.end()
#define N 100009
#define M 1000009
#define mod 1000000007

int n;
int a, b;
int tree[4 * N + 9];
vector<int> v[N];
vector<int> tour;
vector<int> height;
int first[N];

void build(int l, int r, int idx)
{
	if (l == r)
	{
		tree[idx] = l;
		return;
	}
	int mid = (l + r) / 2;

	build(l, mid, 2 * idx + 1);
	build(mid + 1, r, 2 * idx + 2);

	// tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);

	if (height[tree[2 * idx + 1]] < height[tree[2 * idx + 2]])
	{
		tree[idx] = tree[2 * idx + 1];
	}
	else
	{
		tree[idx] = tree[2 * idx + 2];
	}
}

int query(int l, int r, int s, int e, int idx)
{
	if (l > e || r < s)
	{
		return INT_MIN;
	}

	if (l >= s && r <= e)
	{
		return tree[idx];
	}

	int mid = (l + r) / 2;

	int a = query(l, mid, s, e, 2 * idx + 1);
	int b = query(mid + 1, r, s, e, 2 * idx + 2);

	// Hard-Code corner case
	if (a == INT_MIN)
		return b;
	else if (b == INT_MIN)
		return a;
	else if (height[a] < height[b])
		return a;
	else
		return b;
}

void pre()
{
	memset(tree, INT_MAX, sizeof(tree));
	memset(first,-1,sizeof(first));
	cin >> n;
	for (int i = 0; i < (n - 1); i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void euler(int x, int p, int hgh)
{
	tour.push_back(x);
	height.push_back(hgh);
	for (auto i : v[x])
	{
		if (i == p)
			continue;
		euler(i, x, hgh + 1);
		tour.push_back(x);
		height.push_back(hgh);
	}
}

int32_t main()
{
	IOS;
	pre();
	euler(1, 0, 1);
	int x  = 0 ;
	for (auto i : tour)
	{
		cout << i << " ";
		if(first[i]==-1)
		{
			first[i] = x;
		}
		x++;
	}
	cout << endl;
	for (auto i : height)
	{
		cout << i << " ";
	}
	cout << endl;

	build(0, tour.size() - 1, 0);
	
	cout<<tour[query(0,tour.size()-1,first[5],first[7],0)]<<endl;

}