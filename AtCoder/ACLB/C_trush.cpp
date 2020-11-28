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
#define P pair<int,int>
#define F first
#define S second

using namespace std;

int main(){
    int n,m,ans=0;
    cin >> n >> m;
    vector<P> ab(m);
    int input,input1;
    Srep(m){
        cin >> input >> input1;
        ab[i].F = input - 1;
        ab[i].S = input1 - 1;
    }
    vector<bool> dp(n);
    Srep(n) dp[i] = false;
    Vsort(ab);
    dp[ab[0].F] = true;
    Vreverse(ab);
    Srep(n){
        int s = ab.size();
        if(ab[s-1].F == i){
            dp[ab[s-1].S] = true;
            ab.pop_back();
        }else if(ab[s-1].S == i){
            dp[ab[s-1].F] = true;
            ab.pop_back();
        }
    }
    Srep(n) if(dp[i] == false) ans++;
    cout << ans << endl;
}