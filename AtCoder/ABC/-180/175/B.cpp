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
    int n, ans = 0;
    cin >> n;
    vi64 l(n);
    Srep(n) cin >> l[i];
    Vsort(l);
    Srep(n-2) Lrep(j,i+1,n-1) Lrep(k,j+1,n){
        if((l[i]!=l[j]) && (l[i]!=l[k]) && (l[j]!=l[k])){
            if(l[i] + l[j] > l[k]) ans++;
        }
    }
    cout << ans << endl;
}