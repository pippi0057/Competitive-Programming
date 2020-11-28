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
#define vvi vector<vi>
#define vvi64 vector<vi64>

using namespace std;

int main(){
    int n;
    cin >> n;
    Lrep(i,1,n+1){
        if(i % 3 == 0) cout << ' ' << i;
        else if(i % 10 == 3) cout << ' ' << i;
        else if((i - (i % 10)) / 10 == 3) cout << ' ' << i;
        else if((i - (i % 100)) / 100 == 3) cout << ' ' << i;
        else if((i - (i % 1000)) / 1000 == 3) cout << ' ' << i;
    }
    cout << endl;
}