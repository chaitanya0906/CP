// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050eda/00000000001198c3

// Energy Stones Question

#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 200009
#define M 509
#define mod 1000000007
#define debug cout << "There There\n";
#define debug1(x) cout << "\nValue is " << x << endl
#define debug2(x, y) cout << "\nValue is " << x << " " << y << endl
#define debug3(x, y, z) cout << "\nValue is " << x << " " << y << " " << z << endl
#define pq priority_queue<int>
#define mpq priority_queue<int, vector<int>, greater<int>>
#define pr pair<int, int>
#define mx INT_MAX
#define lmx LLONG_MAX
#define err return 0
#define all(a) a.begin(), a.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int t, n;
vector<pair<pr, int>> v;
vector<vector<int>> dp;

bool cmp(pair<pr, int> a, pair<pr, int> b)
{
	return ((a.ss * b.ff.ff) > (b.ss * a.ff.ff));
}

int solve()
{
	cin >> n;

	v.clear();

	v.resize(n);

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].ff.ff >> v[i].ff.ss >> v[i].ss;
		sum += v[i].ff.ff;
	}

	sort(all(v), cmp);

	// dp[TIME][NUMOFSTONESTAKEN] is the amount of energy taken given time T and numofstones

	dp.resize(n + 1);

	for (int i = 0; i <= n; i++)
	{
		dp[i].resize(sum + 1, 0);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].ff.ff; j++)
		{
			//cout<<i<<" "<<j<<endl;
			dp[i + 1][j] = dp[i][j];
			if (j > 0)
			{
				dp[i + 1][j] = max(dp[i + 1][j - 1], dp[i + 1][j]);
			}
		}
		for (int j = v[i].ff.ff; j <= sum; j++)
		{
			//cout<<i<<" "<<j<<endl;
			dp[i + 1][j] = dp[i][j - v[i].ff.ff] - ((j - v[i].ff.ff) * v[i].ss) + v[i].ff.ss;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j > 0)
			{
				dp[i + 1][j] = max(dp[i + 1][j - 1], dp[i + 1][j]);
			}
		}
	}

	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	return dp[n][sum];
}

int32_t main()
{
	//IOS;

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";

		cout << solve() << endl;
	}

	return 0;
}