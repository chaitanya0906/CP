#include <bits/stdc++.h>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

#define IOS                               \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define all(a) a.begin(), a.end()
#define N 200009
#define M 509
#define mod 1000000007

int n, m, q, x;
vector<pair<int, int>> a;
vector<pair<int, int>> t;

int32_t main()
{
        IOS;
        T tree;
        cin >> n >> m >> q;
        a.resize(m, {0, x});

        for (int i = 0; i < m; i++)
        {
                a[i] = {0, i};
        }

        for (int i = 0; i < n; i++)
        {
                cin >> x;
                x--;
                a[x].first++;
        }

        sort(all(a));

        t.resize(q, {0, 0});

        for (int i = 0; i < q; i++)
        {
                cin >> t[i].first;
                t[i].second = i;
                t[i].first -= n;
        }

        sort(all(t));

        vector<int> daysToEquify;

        daysToEquify.push_back(0);

        int days = 0;

        for (int i = 1; i < m; i++)
        {
                days += ((a[i].first - a[i - 1].first) * (i));
                daysToEquify.push_back(days);
        }

        // for (auto i : daysToEquify)
        // {
        // 	cout << i << " dbg" << endl;
        // }

        vector<int> answer;
        answer.resize(q);

        int daysTaken = 0;
        for (auto ij : t)
        {
                int i = ij.first;
                auto it = lower_bound(all(daysToEquify), i);

                int rem = (it - daysToEquify.begin());

                if (rem > daysTaken)
                {
                        for (int j = daysTaken; j < rem; j++)
                        {
                                tree.insert(a[j].second);

                                // cout << "insert " << a[j].second << endl;
                        }
                        daysTaken = rem;
                }

                int days = i - daysToEquify[(it - daysToEquify.begin()) - 1];

                int ans = (days) % rem;

                ans -= 1;
                ans += rem;
                ans %= rem;

                // cout << ans << endl;

                ans = *tree.find_by_order(ans);

                // for (int i = 0; i < daysTaken; i++)
                // {
                // 	cout << *tree.find_by_order(i) << " ith " << i << endl;
                // }
                // cout << ans << endl;
                answer[ij.second] = ans;
        }

        for (auto i : answer)
        {
                cout << (i + 1) << " ";
        }
        cout << endl;
}