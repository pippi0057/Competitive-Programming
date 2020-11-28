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
#define Lrep(i,a,n) for(int64_t i = (a); i < (n); i++)
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
    vi a(n,0);
    Srep(n){
        int input;
        cin >> input;
        a[input-1]++;
    }
    Vsort(a);
    int temp = -1, i = 0;
    while(temp == -1){
        if(a[i] != 0) temp = i;
        i++;
    }
    vi b(a.begin() + temp,a.end());
    int m = b.size();
    m -= k;
    if(m <= 0){
        cout << 0 << endl;
        return 0;
    }
    int ans=0;
    Srep(m) ans += b[i];
    cout << ans << endl;
}