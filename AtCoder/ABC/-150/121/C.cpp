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
 
using namespace std;

int main(){
    int64_t n, m, ans = 0, i = 0;
    cin >> n >> m;
    vector<pair<int,int>> ab(n);
    Srep(n) cin >> ab[i].first >> ab[i].second;
    Vsort(ab);
    while(true){
        if(m > ab[i].second){
            ans += ab[i].first * ab[i].second;
            m -= ab[i].second;
            i++;
        }
        if(m <= ab[i].second){
            ans += m * ab[i].first;
            cout << ans << endl;
            return 0;
        }
    }
}