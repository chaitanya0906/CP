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
#define N 1009
#define M 1000009
#define mod 1000000007

int n;
int a, b;
int tree[4 * N + 9];
bool isRoot[N];
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
        memset(tree, 0, sizeof(tree));
        memset(first, -1, sizeof(first));
        memset(isRoot, true, sizeof(isRoot));
        tour.clear();
        height.clear();
        for (int i = 0; i < N; i++)
        {
                v[i].clear();
        }
}

void euler(int x, int p, int hgh)
{
        tour.push_back(x);
        first[x] = (tour.size() - 1);
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
        int t, q;
        cin >> t;
        for (int test = 1; test <= t; test++)
        {
                cout << "Case " << test << ":\n";
                pre();
                cin >> n;
                for (int i = 1; i <= n; i++)
                {
                        cin >> a;
                        while (a--)
                        {
                                cin >> b;
                                v[i].push_back(b);
                                isRoot[b] = false;
                        }
                }
                int root = -1;
                for (int i = 1; i <= n; i++)
                {
                        if (isRoot[i])
                        {
                                root = i;
                        }
                }
                euler(root, 0, 1);
                build(0, tour.size() - 1, 0);
                cin >> q;
                while (q--)
                {
                        cin >> a >> b;
                        if (first[a] > first[b])
                                swap(a, b);
                        cout << tour[query(0, tour.size() - 1, first[a], first[b], 0)] << endl;
                }
        }
}