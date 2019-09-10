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
#define maxx 100009
#define M 1000009
#define mod 1000000007

int n, m;
string s;
char seeYaa[7] = " abcde";

const int ALPHABET_SIZE = 26;

struct TrieNode
{
        struct TrieNode *children[ALPHABET_SIZE];
        int isEndOfWord = 0;
};

struct TrieNode *root;

struct TrieNode *getNode(void)
{
        struct TrieNode *pNode = new TrieNode;
        pNode->isEndOfWord = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
                pNode->children[i] = NULL;
        return pNode;
}

void insert(string key)
{
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
                int index = key[i] - 'a';
                if (!pCrawl->children[index])
                        pCrawl->children[index] = getNode();
                pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord++;
}

int search(string key)
{
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
                int index = key[i] - 'a';
                if (!pCrawl->children[index])
                        return false;
                pCrawl = pCrawl->children[index];
        }
        if (pCrawl == NULL)
                return 0;
        return pCrawl->isEndOfWord;
}

int32_t main()
{
        IOS;

        cin >> n >> m;

        root = getNode();
        while (n--)
        {
                cin >> s;
                Add(s);
        }

        while (m--)
        {
                cin >> s;
                int ans = 0;

                string see;
                for (int i = 0; i < 216; i++)
                {
                        see = "";
                        int alloc = 0;
                        for (int j = 0; j < s.length(); j++)
                        {
                                if (s[j] == '?')
                                {
                                        if (alloc == 0)
                                        {
                                                see += seeYaa[i % 6];
                                                alloc++;
                                        }
                                        else if (alloc == 1)
                                        {
                                                see += seeYaa[(i / 6) % 6];
                                                alloc++;
                                        }
                                        else
                                        {
                                                see += seeYaa[(i / 36) % 6];
                                                alloc++;
                                        }
                                }
                                else
                                {
                                        see += s[j];
                                }
                                if (see[see.length() - 1] == ' ')
                                {
                                        see.pop_back();
                                }
                        }

                        if (search(see))
                        {
                                if (alloc == 3)
                                        ans++;
                                else if (alloc == 2 && i < 36)
                                        ans++;
                                else if (alloc == 1 && i < 6)
                                        ans++;
                                else if (alloc == 0 && i == 0)
                                        ans++;
                        }
                }

                cout << ans << endl;
        }
}