#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip> 
#include <cmath>
#include <stack>
#include <cstring>
#include <climits>
using namespace std;

#define FASTIO() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define LIM 1005
#define F first
#define S second
#define pb push_back
#define SZ(vec) int(vec.size())
#define f(i, s, n) for(int i = s; i < n; i++)
#define all(vec) vec.begin(),vec.end()

typedef long long ll;
typedef pair<ll, ll> pll;
ll mod = 1000000007;
ll arr[LIM][LIM];

// pair<ll, vector<pll> > aSpiralClock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[k][i]);
//             path.push_back({k + 1, i + 1});
//             ind++;
//         }
//         k++;
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][n - 1]);
//             path.push_back({i + 1, n});
//             ind++;
//         }
//         n--;
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[m - 1][i]);
//                 path.push_back({m, i + 1});
//                 ind++;
//             }
//             m--;
//         }
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][l]);
//                 path.push_back({i + 1, l + 1});
//                 ind++;
//             }
//             l++;
//         }
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > aSpiralAnticlock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][l]);
//             path.push_back({i + 1, l + 1});
//             ind++;
//         }
//         l++;
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[m - 1][i]);
//             path.push_back({m, i + 1});
//             ind++;
//         }
//         m--;
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][n - 1]);
//                 path.push_back({i + 1, n});
//                 ind++;
//             }
//             n--;
//         }
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[k][i]);
//                 path.push_back({k + 1, i + 1});
//                 ind++;
//             }
//             k++;
//         }
        
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > bSpiralClock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][n - 1]);
//             path.push_back({i + 1, n});
//             ind++;
//         }
//         n--;
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[m - 1][i]);
//                 path.push_back({m, i + 1});
//                 ind++;
//             }
//             m--;
//         }
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][l]);
//                 path.push_back({i + 1, l + 1});
//                 ind++;
//             }
//             l++;
//         }
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[k][i]);
//             path.push_back({k + 1, i + 1});
//             ind++;
//         }
//         k++;
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > bSpiralAnticlock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[k][i]);
//                 path.push_back({k + 1, i + 1});
//                 ind++;
//             }
//             k++;
//         }
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][l]);
//             path.push_back({i + 1, l + 1});
//             ind++;
//         }
//         l++;
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[m - 1][i]);
//             path.push_back({m, i + 1});
//             ind++;
//         }
//         m--;
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][n - 1]);
//                 path.push_back({i + 1, n});
//                 ind++;
//             }
//             n--;
//         }
        
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > cSpiralClock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[m - 1][i]);
//                 path.push_back({m, i + 1});
//                 ind++;
//             }
//             m--;
//         }
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][l]);
//                 path.push_back({i + 1, l + 1});
//                 ind++;
//             }
//             l++;
//         }
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[k][i]);
//             path.push_back({k + 1, i + 1});
//             ind++;
//         }
//         k++;
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][n - 1]);
//             path.push_back({i + 1, n});
//             ind++;
//         }
//         n--;
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > cSpiralAnticlock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][n - 1]);
//                 path.push_back({i + 1, n});
//                 ind++;
//             }
//             n--;
//         }
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[k][i]);
//                 path.push_back({k + 1, i + 1});
//                 ind++;
//             }
//             k++;
//         }
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][l]);
//             path.push_back({i + 1, l + 1});
//             ind++;
//         }
//         l++;
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[m - 1][i]);
//             path.push_back({m, i + 1});
//             ind++;
//         }
//         m--;
        
        
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > dSpiralClock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][l]);
//                 path.push_back({i + 1, l + 1});
//                 ind++;
//             }
//             l++;
//         }
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[k][i]);
//             path.push_back({k + 1, i + 1});
//             ind++;
//         }
//         k++;
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][n - 1]);
//             path.push_back({i + 1, n});
//             ind++;
//         }
//         n--;
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[m - 1][i]);
//                 path.push_back({m, i + 1});
//                 ind++;
//             }
//             m--;
//         }
        
//     }
//     return {ans, path};
// }

// pair<ll, vector<pll> > dSpiralAnticlock (int n, int m) {
//     int i, k = 0, l = 0;
//     ll ind = 1;
//     ll ans = 0;
//     vector<pll> path;
//     while (k < m && l < n) {
//         for (i = l; i < n; ++i) {
//             ans += (ind * arr[m - 1][i]);
//             path.push_back({m, i + 1});
//             ind++;
//         }
//         m--;
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 ans += (ind * arr[i][n - 1]);
//                 path.push_back({i + 1, n});
//                 ind++;
//             }
//             n--;
//         }
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 ans += (ind * arr[k][i]);
//                 path.push_back({k + 1, i + 1});
//                 ind++;
//             }
//             k++;
//         }
//         for (i = k; i < m; ++i) {
//             ans += (ind * arr[i][l]);
//             path.push_back({i + 1, l + 1});
//             ind++;
//         }
//         l++;
//     }
//     return {ans, path};
// }

void print_path(pair< ll, vector <pll> > &ans) {
    cout << ans.F << endl;
    for (auto val : ans.S) {
        cout << val.F << " " << val.S << endl;
    }
}
int main() {
    FASTIO();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    ll _max = 0;
    pll ans;
    f (i, 0, n) {
        f (j, 0, n) {
            cin >> arr[i][j];
            if (arr[i][j] > _max) {
                _max = arr[i][j];
                ans = {i + 1, j + 1};
            }
        }
    }
    cout << "1 " << endl;
    cout << ans.F << " " << ans.S << endl;
    // pair<ll, vector<pll> > ans;
    // pair<ll ,vector<pll> > ac = aSpiralClock(n, n);
    // pair<ll ,vector<pll> > bc = bSpiralClock(n, n);
    // pair<ll ,vector<pll> > cc = cSpiralClock(n, n);
    // pair<ll ,vector<pll> > dc = dSpiralClock(n, n);
    // pair<ll, vector<pll> > aac = aSpiralAnticlock(n, n);
    // pair<ll, vector<pll> > bac = bSpiralAnticlock(n, n);
    // pair<ll, vector<pll> > cac = cSpiralAnticlock(n, n);
    // pair<ll, vector<pll> > dac = dSpiralAnticlock(n, n);
    // if (ac.F > _max) {
    //     ans = ac;
    //     _max = ac.F;
    // }
    // if (bc.F > _max) {
    //     ans = bc;
    //     _max = bc.F;
    // }
    // if (cc.F > _max) {
    //     ans = cc;
    //     _max = cc.F;
    // }
    // if (dc.F > _max) {
    //     ans = dc;
    //     _max = dc.F;
    // } 
    // if (aac.F > _max) {
    //     ans = aac;
    //     _max = aac.F;
    // }
    // if (bac.F > _max) {
    //     ans = bac;
    //     _max = bac.F;
    // }
    // if (cac.F > _max) {
    //     ans = cac;
    //     _max = cac.F;
    // }
    // if (dac.F > _max) {
    //     ans = dac;
    //     _max = dac.F;
    // }
    // print_path(ans);
    return 0;
}