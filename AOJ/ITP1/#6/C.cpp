#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define Srep(n) for(int64_t i = 0; i < int64_t(n); i++)
#define Lrep(i,a,n) for(int64_t i = int64_t(a); i < int64_t(n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>
#define vc vector<char>
#define vvc vector<vc>
using namespace std;

int main(){
    vector<vvi> count(4,vvi(3,vi(10,0)));
    int n;
    cin >> n;
    Srep(n){
        int b,f,r,v;
        cin >> b >> f >> r >> v;
        count[b-1][f-1][r-1] += (v);
    }
    Srep(4){
        Lrep(j,0,3){
            Lrep(k,0,10){
                cout << ' ' << count[i][j][k];
            }
            cout << endl;
        }
        if(i != 3) cout << "####################" << endl;
    }
}
