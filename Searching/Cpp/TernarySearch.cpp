#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define fr(n) for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end())
#define srtdec(v) sort(v.begin(), v.end(), greater<int>());
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vcini(n)                \
    vector<int> v;              \
    for (int i = 0; i < n; i++) \
    {                           \
        int e;                  \
        cin >> e;               \
        v.push_back(e);         \
    }
#define cini(x) \
    int x;      \
    cin >> x;
#define TC(t) \
    int t;    \
    cin >> t; \
    while (t--)
int terSearch(vector<int> &v, int key)
{
    int l = 0, h = v.size() - 1;
    while (l <= h)
    {
        int mid1 = l + (h - l) / 3;
        int mid2 = h - (h - l) / 3;
        if (v[mid1] == key)
        {
            return mid1;
        }
        if (v[mid2] == key)
        {
            return mid2;
        }
        if (v[mid1] > key)
        {
            h = mid1 - 1;
        }
        else if (key > v[mid2])
        {
            l = mid2 + 1;
        }
        else
        {
            l = mid1 + 1;
            h = mid2 - 1;
        }
    }
    return -1;
}
int main()
{
    fastio();

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int key;
    cin >> key;
    int ans = terSearch(v, key);
    if (ans == -1)
    {
        cout << "NOT PRESENT" << endl;
    }
    else
    {
        cout << "PRESENT AT " << ans << endl;
    }
    return 0;
}
