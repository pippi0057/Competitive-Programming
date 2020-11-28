#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

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
    int n,k;
    cin >> n >> k;
    vi dp(110000);
    vi list;
    Srep(k){
        int a,b;
        cin >> a >> b;
        Lrep(j,a,b+1) list.push_back(j);
    }
    Vsort(list);
    dp[0] = 0;
    Srep(n){
        Lrep(j,0,list.size()){
            dp[i+list[j]] += dp[i] + 1;
        }
    }
    cout << dp[n-2] << endl;
}