#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
#include<queue>
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

int gcd(int x, int y){
    return x % y == 0 ? y : gcd(y, x % y);
}

int main(){
    int n,ans;
    cin >> n;
    if(n == 1){
        int input;
        cin >> input;
        cout << input << endl;
        return 0;
    }
    vi a(2);
    cin >> a[0] >> a[1];
    ans = gcd(a[0],a[1]);
    Lrep(i,2,n){
        int input;
        cin >> input;
        ans = gcd(ans,input);
    }
    cout << ans << endl;
}