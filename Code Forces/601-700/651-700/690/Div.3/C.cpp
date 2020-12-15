#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
#define setup cin.tie(0); ios::sync_with_stdio(false); cout << setprecision(20) << fixed;
#define db double
#define P pair<int,int>
#define F first
#define S second
#define endl "\n"
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define RoundUp(a,b) ((a) % (b) ? (a) / (b) + 1 : (a) / (b))
#define vi vector<int>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

vvi memo = {
    {},
    {1},
    {2},
    {3},
    {4},
    {5},
    {6},
    {7},
    {8},
    {9},
    {1, 9},
    {2, 9},
    {3, 9},
    {4, 9},
    {5, 9},
    {6, 9},
    {7, 9},
    {8, 9},
    {1, 8, 9},
    {2, 8, 9},
    {3, 8, 9},
    {4, 8, 9},
    {5, 8, 9},
    {6, 8, 9},
    {7, 8, 9},
    {1, 7, 8, 9},
    {2, 7, 8, 9},
    {3, 7, 8, 9},
    {4, 7, 8, 9},
    {5, 7, 8, 9},
    {6, 7, 8, 9},
    {1, 6, 7, 8, 9},
    {2, 6, 7, 8, 9},
    {3, 6, 7, 8, 9},
    {4, 6, 7, 8, 9},
    {5, 6, 7, 8, 9},
    {1, 5, 6, 7, 8, 9},
    {2, 5, 6, 7, 8, 9},
    {3, 5, 6, 7, 8, 9},
    {4, 5, 6, 7, 8, 9},
    {1, 4, 5, 6, 7, 8, 9},
    {2, 4, 5, 6, 7, 8, 9},
    {3, 4, 5, 6, 7, 8, 9},
    {1, 3, 4, 5, 6, 7, 8, 9},
    {2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
};

signed main(){
    setup;
    int att;
    cin >> att;
    while(att--){   
        int n;
        cin >> n;
        if(n > 45) cout << -1 << endl;
        else{
            Srep(memo[n].size()) cout << memo[n][i];
            cout << endl;
        }
    }
}