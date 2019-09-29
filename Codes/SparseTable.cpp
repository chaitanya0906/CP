// https://codeforces.com/problemset/problem/359/D
#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);                      \
	cout.precision(10);               \
	cout << fixed;
#define int long long int
#define pb push_back
#define endl "\n"
#define all(a) a.begin(), a.end()
#define N 300009
#define M 1000009
#define mod 1000000007
int powi(int a, int b)
{
	if (b == 0)
		return 1;
	int see = powi(a, b / 2);
	see *= see;
	see %= mod;
	if (b % 2)
		see *= a;
	see %= mod;
	return see;
}
int k = 17;
int n;
int a[N];
int tableGcd[N][18];
int tableMin[N][18];

void pre()
{
}

void buildGcd()
{
	for (int i = 0; i < n; i++)
		tableGcd[i][0] = a[i];
	for (int j = 1; j <= k; j++)
	{
		for (int i = 0; i <= n - (1 << j); i++)
			tableGcd[i][j] = __gcd(tableGcd[i][j - 1], tableGcd[i + (1 << (j - 1))][j - 1]);
	}
}

void buildMin()
{
	for (int i = 0; i < n; i++)
		tableMin[i][0] = a[i];
	for (int j = 1; j <= k; j++)
	{
		for (int i = 0; i <= n - (1 << j); i++)
			tableMin[i][j] = min(tableMin[i][j - 1], tableMin[i + (1 << (j - 1))][j - 1]);
	}
}

int queryGCD(int L, int R)
{
	int answer = 0;
	for (int j = k; j >= 0; j--)
	{
		if (L + (1 << j) - 1 <= R)
		{
			answer = __gcd(answer, tableGcd[L][j]);
			L += 1 << j;
		}
	}
	return answer;
}

int queryMin(int L, int R)
{
	int answer = INT_MAX;
	for (int j = k; j >= 0; j--)
	{
		if (L + (1 << j) - 1 <= R)
		{
			answer = min(answer, tableMin[L][j]);
			L += 1 << j;
		}
	}
	return answer;
}

bool isIt(int x, int y)
{
	return (queryMin(x, y) == queryGCD(x, y));
}

bool check(int len)
{
	for (int i = 0; i < n; i++)
	{
		// check from i to i + len - 1
		if ((i + len - 1) >= n)
			break;
		if (isIt(i, i + len - 1))
		{
			// cout << i << " " << len << endl;
			return 1;
		}
	}
	return 0;
}

int32_t main()
{
	IOS;
	pre();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	buildGcd();
	buildMin();
	int l = 1;
	int r = n;
	int mid;
	while (l < r)
	{
		mid = (l + r + 1) / 2;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = (mid - 1);
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		if ((i + l - 1) >= n)
			break;
		// gcd == min cout
		if (isIt(i, i + l - 1))
		{
			ans.push_back(i+1);
		}
	}
	cout<<ans.size()<<" "<<(l-1)<<endl;
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	return 0;
}