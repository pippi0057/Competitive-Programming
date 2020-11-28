#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    int Max = 1, Min = n;
    Srep(m){
        int l,r;
        cin >> l >> r;
        Max = max(l,Max);
        Min = min(r,Min);
    }
    if(Min - Max < 0) ans = 0;
  	else ans = Min - Max + 1;
    cout << ans << endl;
}