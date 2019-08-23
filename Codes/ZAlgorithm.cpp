// z algorithm
// https://codeforces.com/contest/126/problem/B

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
#define N 2009
#define M 509
#define mod 9988244853
#define debug cout << "There There\n";
#define debug1(x) cout << "\nValue is " << x << endl
#define debug2(x, y) cout << "\nValue is " << x << " " << y << endl
#define debug3(x, y, z) cout << "\nValue is " << x << " " << y << " " << z << endl
#define pq priority_queue<int>
#define mpq priority_queue<int, vector<int>, greater<int>>
#define pr pair<int, int>
#define mx INT_MAX
#define lmx LLONG_MAX
#define dek "Just a legend"
#define err return 0
#define all(a) a.begin(), a.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
vector<int> zval;
int n;

int32_t main()
{
        IOS;

        cin >> s;
        n = s.length();

        zval.resize(n, 0);

        int L = 0, R = 0;
        for (int i = 1; i < n; i++)
        {
                if (i > R)
                {
                        L = R = i;
                        while (R < n && s[R - L] == s[R])
                                R++;
                        zval[i] = R - L;
                        R--;
                }
                else
                {
                        int k = i - L;
                        if (zval[k] < R - i + 1)
                                zval[i] = zval[k];
                        else
                        {
                                L = i;
                                while (R < n && s[R - L] == s[R])
                                        R++;
                                zval[i] = R - L;
                                R--;
                        }
                }
        }

        // for (auto i : zval)
        // {
        //         cout << i << " ";
        // }
        // cout << endl;

        vector<int> maxi;
        maxi.resize(n, 0);

        for (int i = 1; i < n; i++)
        {
                maxi[i] = max(maxi[i - 1], zval[i]);
        }

        int suff = -1;

        for (int i = (n - 1); i >= 1; i--)
        {
                if ((zval[i] + i) == n && maxi[i - 1] >= zval[i])
                {
                        suff = i;
                        // debug3(i,maxi[i-1],zval[i]);

                }
        }

        // cout << suff << endl;

        if (suff == -1)
        {
                cout << dek << endl;
                err;
        }

        int len = n - suff;

        int pre = -1;

        for (int i = 1; i < suff; i++)
        {
                if (zval[i] >= len)
                {
                        pre = i;
                        break;
                }
        }

        // cout << pre << endl;

        if (pre == -1)
        {
                cout << dek << endl;
                err;
        }

        for (int i = 0; i < len; i++)
        {
                cout << s[i];
        }
        cout << endl;

        return 0;
}