#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
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
    int h,w,ans=0;
    cin >> h >> w;
    vvc s(h,vc(w));
    rep2d(h,w) cin >> s[i][j];
    auto up = [s,h,w](int a, int b) -> bool{
        if(a == 0) return false;
        else if(s[a-1][b] == '#') return false;
        else return true;
    };
    auto down = [s,h,w](int a, int b) -> bool{
        if(a == h-1) return false;
        else if(s[a+1][b] == '#') return false;
        else return true;
    };
    auto right = [s,h,w](int a, int b) -> bool{
        if(b == w-1) return false;
        else if(s[a][b+1] == '#') return false;
        else return true;
    };
    auto left = [s,h,w](int a, int b) -> bool{
        if(b == 0) return false;
        else if(s[a][b-1] == '#') return false;
        else return true;
    };
    rep2d(h,w){
        if(s[i][j] == '.'){
            if(up(i,j)) ans++;
            if(down(i,j)) ans++;
            if(right(i,j)) ans++;
            if(left(i,j)) ans++;   
        }
    }
    cout << ans / 2 << endl;
}