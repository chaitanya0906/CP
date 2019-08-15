/* https://codeforces.com/problemset/problem/1203/F2 */

// DYnamic a bit Knapsack Practice Question

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

vector<pr> pos, neg;
int n, r, x, y;

bool cmp(pr a, pr b)
{
        if ((a.first + a.second) < (b.first + b.second))
                return 1;
        return 0;
}

int32_t main()
{
        IOS;

        cin >> n >> r;

        for (int i = 0; i < n; i++)
        {
                cin >> x >> y;
                if (y < 0)
                {
                        neg.push_back({max(x, -y), y});
                }
                else
                {
                        pos.push_back({x, y});
                }
        }

        sort(all(pos));

        sort(all(neg), cmp);
        int ps = 0;
        for (auto i : pos)
        {
                if (i.ff <= r)
                {
                        r += i.ss;
                        ps++;
                }
        }

        vector<vector<int>> dp;
        dp.resize(neg.size() + 1);
        for (int i = 0; i <= neg.size(); i++)
        {
                dp[i].resize(60001, 0);
        }

        for (int i = 0; i < neg.size(); i++)
        {

                for (int j = 0; j < neg[i].ff; j++)
                {
                        dp[i + 1][j] = dp[i][j];
                }

                for (int j = neg[i].ff; j <= 60000; j++)
                {
                        if ((j + neg[i].ss) >= 0)
                        {
                                dp[i + 1][j] = max(dp[i][j], dp[i][j + neg[i].ss] + 1);
                        }
                        dp[i + 1][j] = max(dp[i + 1][j - 1], dp[i + 1][j]);
                }
        }

        int tk = 0;

        for (int i = 0; i <= r; i++)
        {
                tk = max(tk, dp[neg.size()][i]);
        }

        cout << (ps + tk) << endl;

        return 0;
}