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
    int n;
    cin >> n;
    vector< vector<bool> > card(4, vector<bool>(13,1));
    Srep(n){
        char c;
        int a,b;
        cin >> c >> b;
        if(c == 'S') a = 0;
        else if(c == 'H') a = 1;
        else if(c == 'C') a = 2;
        else a = 3;
        card[a][b-1] = 0;
    }
    rep2d(4,13){
        if(card[i][j]){
            char s;
            if(i == 0) s = 'S';
            else if(i == 1) s = 'H';
            else if(i == 2) s = 'C';
            else s = 'D';
            cout << s << ' ' << j + 1 << endl;
        }
    }
}
