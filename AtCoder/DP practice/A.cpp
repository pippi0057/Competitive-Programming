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
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>

using namespace std;

int main(){
    int n;
    cin >> n;
    vi h(n),dp(n);
    Srep(n) cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    Lrep(i,2,n){
        if(dp[i-1] + abs(h[i] - h[i-1]) < dp[i-2] + abs(h[i] - h[i-2])){
            dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        }else{
            dp[i] = dp[i-2] + abs(h[i] - h[i-2]);
        }
    }
    cout << dp[n-1] << endl;
}