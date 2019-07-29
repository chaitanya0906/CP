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
#define N 300009
#define NN 3000009
#define M 11
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

int dp[N][M];
int n, m, k;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	dp[0][0] = 0;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			dp[i][j] = INT_MIN;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][(j + 1) % m] = dp[i - 1][j] + a[i];
			if ((j + 1) == m)
			{
				dp[i][(j + 1) % m] -= k;
			}
		}
		dp[i][0] = max((int)0, dp[i][0]);
		ans = max(ans, (*max_element(dp[i], dp[i] + m)) - k);
		ans = max(ans, dp[i][0]);
	}

	cout << ans << endl;
	err;
}