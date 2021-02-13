#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
 
#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.begin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>
#define vc vector<char>
 
using namespace std;

int main(){
    int n,ans=0;
    cin >> n;
    vi s(n);
    Srep(n){
        char input;
        cin >> input;
        if(input == 'A') s[i] = 1;
        if(input == 'T') s[i] = 2;
        if(input == 'C') s[i] = 3;
        if(input == 'G') s[i] = 4;
    }
    Lrep(i,0,n+1) Lrep(j,i,n+1){
        vi a(s.begin()+i, s.begin()+j), b(s.begin()+i, s.begin()+j);
        int m = a.size();
        if((m == 1)||(m == 0)) continue;
        Vreverse(b);
        vi c(m);
        Lrep(k,0,m){
            if(a[k] == 1) c[k] = 2;
            if(a[k] == 2) c[k] = 1;
            if(a[k] == 3) c[k] = 4;
            if(a[k] == 4) c[k] = 3;
        }
        if(b == c) ans++;
    }
    cout << ans << endl;
}