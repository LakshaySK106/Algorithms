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
int linSearch(vector<int> &v, int key)
{

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            return i;
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
    int ans = linSearch(v, key);
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
