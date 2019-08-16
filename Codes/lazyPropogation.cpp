// Correct Lazy Propogation Code

#include <bits/stdc++.h>
using namespace std;

#define N 100009

int n, t, s;
int a[N], tree[4 * N + 2], lazy[4 * N + 2];
map<int, vector<int>> mp;
map<int, int> pos;

// void build(int l, int r, int idx)
// {
//         if (l == r)
//         {
//                 tree[idx] = a[l];
//                 return;
//         }
//         int mid = (l + r) / 2;

//         build(l, mid, 2 * idx + 1);
//         build(mid + 1, r, 2 * idx + 2);

//         tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
// }

void update(int l, int r, int s, int e, int idx, int val)
{

        if (lazy[idx] != 0)
        {
                tree[idx] += lazy[idx];
                if (l != r)
                {
                        lazy[2 * idx + 1] += lazy[idx];
                        lazy[2 * idx + 2] += lazy[idx];
                }
                lazy[idx] = 0;
        }

        if (l > e || r < s)
        {
                return;
        }
        int mid = (l + r) / 2;

        if (l >= s && r <= e && (l != r))
        {
                tree[idx] += val;
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
                return;
        }

        else if (l >= s && r <= e)
        {
                tree[idx] += val;
                return;
        }

        update(l, mid, s, e, 2 * idx + 1, val);
        update(mid + 1, r, s, e, 2 * idx + 2, val);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
}

int query(int l, int r, int s, int e, int idx)
{
        if (l > e || r < s)
        {
                return INT_MIN;
        }

        if (lazy[idx] != 0)
        {
                tree[idx] += lazy[idx];
                int val = lazy[idx];
                lazy[idx] = 0;
                if (l != r)
                {
                        lazy[2 * idx + 1] += val;
                        lazy[2 * idx + 2] += val;
                }
        }

        if (l >= s && r <= e)
        {
                return tree[idx];
        }

        int mid = (l + r) / 2;

        int a = query(l, mid, s, e, 2 * idx + 1);
        int b = query(mid + 1, r, s, e, 2 * idx + 2);

        return max(a, b);
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        cin >> t;

        for (int i = 1; i <= t; i++)
        {
                memset(tree, 0, sizeof(tree));
                memset(lazy, 0, sizeof(lazy));
                cout << "Case #" << i << ": ";

                cin >> n >> s;

                mp.clear();

                int x;

                for (int i = 0; i < n; i++)
                {
                        cin >> x;
                        a[i] = x;
                        mp[x].push_back(i);
                        pos[i] = mp[x].size();
                }

                int mx = 0;

                for (int i = 0; i < n; i++)
                {
                        int l = -1;
                        int r = -1;

                        if (pos[i] > (s))
                        {
                                r = mp[a[i]][pos[i] - s - 1];
                        }
                        if (pos[i] > (s + 1))
                        {
                                l = mp[a[i]][pos[i] - s - 2];
                        }

                        update(0, n - 1, l+1, i, 0, 1);

                        if (r != -1)
                        {
                                update(0, n - 1, l + 1, r, 0, -(s + 1));
                                //cout<<(l+1)<<" "<<r<<" is updated\n";
                        }

                        mx = max(mx, query(0, n - 1, 0, i, 0));
                }

                cout << mx << endl;
        }
}