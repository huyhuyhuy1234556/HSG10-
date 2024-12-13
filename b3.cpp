#include "bits/stdc++.h"
using namespace std;
#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
using ll = long long;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n ,  q;
//int a[MAX] , l[MAX] ,r[MAX];
struct Solve
{
    int val, size;
};

/*     Nguyen Huy     */

void run_case() {
	cin >> n >> q;
    vi v(n), Q(n);
    for(int i = 0 ;i < n;i++)
    {
        cin >> v[i];
    }
    for(int i = 0 ; i < q;i++)
    {
        cin >> Q[i];
    }
    vi l(n) , r(n);
    stack<int> s;
    for(int i = 0; i < n;i++)
    {
        while(!s.empty() && v[s.top()] <= v[i] )
        {
            s.pop();
        }
        l[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
    while(!s.empty()) 
    {
        s.pop();
    }
    for(int i = n - 1; i >= 0;i--)
    {
        while(!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        r[i] = (s.empty() ? n : s.top());
        s.push(i);
    }
    // for(int i = 0 ; i < n;i++)
    // {
    //     cout << l[i] << " " << r[i] << endl;
    // }
    vector<Solve> solve(n);
    for(int i = 0;i < n;i++)
    {
        solve[i].val = v[i];
        solve[i].size = r[i] - l[i] - 1; 
    }
    sort(solve.begin(), solve.end(), [](const Solve &a, const Solve &b) {
        return a.val < b.val;
    });
    vi res(n);
    res[0] = solve[0].size;
    for(int i = 1;i < n;i++)
    {
        res[i] = max(res[i - 1],solve[i].size);
    }
    // for(int i = 0;i < n;i++)
    // {
    //     cout << l[i] << " " << r[i] << " " << res[i] << endl;
    // }
    for(int i = 0;i < q;i++)
    {
        int k = Q[i];
        int ans = -1;
        int l = 0, r = n - 1;
        while(l <= r)
        {
            int m = (l + r)/2;
            if(solve[m].val <= k)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if(ans == -1)
        {
            cout << 0 << endl; 
        }
        else
        {
            cout << res[ans] << endl;
        }
    }
   
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
