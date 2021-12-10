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
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vi cards(2 * n);
    Srep(2 * n) cards[i] = i + 1;
    Srep(m){
        int k;
        cin >> k;
        if(k == 0){
            vi card(2*n);
            Lrep(j,0,2*n) card[j] = cards[j];
            Lrep(j,0,n){
            }
        }
    }
}