#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define speed\
    cin.tie(0);\
    ios::sync_with_stdio(false);
#define int long long int
#define db double
#define ldb long double
#define P pair<int,int>
#define F first
#define S second
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>

int32_t main(){
    speed;
    int attempt;
    cin >> attempt;
    Lrep(aaaaa,0,attempt){
        int n;
        cin >> n;
        vector<P> a(n);
        Srep(n){
            cin >> a[i].F;
            a[i].S = i + 1;
        }
        sort(all(a));
        set<int> ans;
        int temp;
        Srep(n){
            auto j = ans.insert(a[i].F);
            if(j.S) temp = a[i].S;
            else temp = 10000000;
        }
        cout << (temp == 10000000 ? -1 : temp) << endl;
    }
}