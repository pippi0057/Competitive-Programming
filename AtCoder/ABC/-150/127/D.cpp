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
    int n,m;
    cin >> n >> m;
    vi64 a;
    Srep(n){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    Srep(m){
        int temp,temp2;
        cin >> temp >> temp2;
        Lrep(j,0,temp) a.push_back(temp2);
        sort(a.begin(), a.end(), greater<int>());
        Lrep(j,0,temp) a.pop_back();
    }
    int64_t ans = 0;
    Srep(n) ans += a[i];
    cout << ans << endl;
}