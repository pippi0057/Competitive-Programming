#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    int n;
    cin >> n;
    vi d(n);
    rep(i,n) cin >> d[i];
    int d_max = d[0];
    rep(i,n){
        d_max < d[i] ? d_max = d[i] : d_max = d_max;
        if(d_max < i * 10){
            cout << "no" << endl;
            return 0;
        }
    }
}